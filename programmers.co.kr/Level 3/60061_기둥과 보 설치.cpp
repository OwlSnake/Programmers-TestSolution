#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

bool isValid(vector<vector<bool>> &pole, vector<vector<bool>> &bar, int size) {
	for (int r = 0; r <= size; r++) {
		for (int c = 0; c <= size; c++) {
			if (!pole[r][c] && !bar[r][c])
				continue;

			if (pole[r][c]) {
				if (r == 0)
					continue;
				if (bar[r][c] || (c > 0 && bar[r][c-1]))
					continue;
				if (r > 0 && pole[r-1][c])
					continue;

				return false;
			}

			if (bar[r][c]) {
				if ((r > 0 && pole[r - 1][c]) || (r > 0 && pole[r - 1][c + 1]))
					continue;
				if (c > 0 && bar[r][c - 1] && bar[r][c + 1])
					continue;

				return false;
			}

		}
	}
	return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {

	vector<vector<bool>> pole(n + 2, vector<bool>(n + 2, false));
	vector<vector<bool>> bar(n + 2, vector<bool>(n + 2, false));

	vector<vector<int>> answer;

	// simulate build
	for (auto& frame : build_frame) {
		int x = frame[0];
		int y = frame[1];
		int type = frame[2];
		int add = frame[3];
		
		// 추가
		if (add == 1) {
			if (type == 0) {
				pole[y][x] = true;

				if (!isValid(pole, bar, n)) {
					pole[y][x] = false;
				}
			}
			else {
				bar[y][x] = true;

				if (!isValid(pole, bar, n)) {
					bar[y][x] = false;
				}
			}
		}
		// 삭제
		else {
			if (type == 0) {
				pole[y][x] = false;

				if (!isValid(pole, bar, n)) {
					pole[y][x] = true;
				}
			}
			else {
				bar[y][x] = false;

				if (!isValid(pole, bar, n)) {
					bar[y][x] = true;
				}
			}
		}
	}

	// make answer from map
	for (int x = 0; x <= n; x++) {
		for (int y = 0; y <= n; y++) {
			if (pole[y][x]) {
				answer.push_back({ x, y, 0 });
			}
			if (bar[y][x]) {
				answer.push_back({ x, y, 1 });
			}
		}
	}

	sort(answer.begin(), answer.end());

	for (auto& a : answer) {
		cout << a[0] << a[1] << a[2] << endl;
	}

	return answer;
}

map<tuple<int, int, int>, int> ress;

bool check() {
	for (auto r : ress) {
		int x, y, a; tie(x, y, a) = r.first;

		if (a == 0) {
			if (y == 0 || ress.count(make_tuple(x - 1, y, 1)) || ress.count(make_tuple(x, y, 1)) || ress.count(make_tuple(x, y - 1, 0)))
				continue;
			else
				return false;
		}

		else if (a == 1) {
			if (ress.count(make_tuple(x, y - 1, 0)) || ress.count(make_tuple(x + 1, y - 1, 0)) || (ress.count(make_tuple(x - 1, y, 1)) + ress.count(make_tuple(x + 1, y, 1)) == 2))
				continue;
			else
				return false;
		}
	}

	return true;
}
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	vector<vector<int>> answer;
	for (auto build : build_frame) {
		tuple<int, int, int> tup = make_tuple(build[0], build[1], build[2]);
		int add = build[3];

		if (add == 1) {
			ress[tup] = true;

			if (check() == false) {
				ress.erase(tup);
			}
		}
		else if (add == 0) {
			ress.erase(tup);

			if (check() == false) {
				ress[tup] = true;
			}
		}

	}

	for (auto res : ress) {
		int x, y, a;
		tie(x, y, a) = res.first;
		vector<int> r = { x,y,a };
		answer.push_back(r);
	}

	sort(answer.begin(), answer.end());

	return answer;
}

void main() {
	solution(5, {{1, 0, 0, 1}, {1, 1, 1, 1}, {2, 1, 0, 1}, {2, 2, 1, 1}, {5, 0, 0, 1}, {5, 1, 0, 1}, {4, 2, 1, 1}, {3, 2, 1, 1}});
	cout << endl;
	solution(5, {{0, 0, 0, 1}, {2, 0, 0, 1}, {4, 0, 0, 1}, {0, 1, 1, 1}, {1, 1, 1, 1}, {2, 1, 1, 1}, {3, 1, 1, 1}, {2, 0, 0, 0}, {1, 1, 1, 0}, {2, 2, 0, 1}});
}