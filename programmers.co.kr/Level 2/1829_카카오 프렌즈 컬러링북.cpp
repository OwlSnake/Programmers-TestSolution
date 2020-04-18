#include <vector>

#include <iostream>
using namespace std;

int M, N;
int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { -1, 1, 0, 0 };
vector<vector<int>> pic;
vector<vector<int>> visited;

bool isIn(int r, int c) {
	return r >= 0 && c >= 0 && r < M && c < N;
}

int findArea(int r, int c) {
	visited[r][c] = 1;
	int areaSize = 1;
	for (int i = 0; i < 4; i++) {
		int newR = r + dy[i];
		int newC = c + dx[i];
		if (!isIn(newR, newC))
			continue;
		if (!visited[newR][newC] && pic[newR][newC] == pic[r][c]) {
			areaSize += findArea(newR, newC);
		}
	}
	return areaSize;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;
	M = m;
	N = n;
	pic = picture;
	visited = vector<vector<int>>(m, vector<int>(n));

	for (int r = 0; r < m; r++) {
		for (int c = 0; c < n; c++)
		{
			if (picture[r][c] == 0 || visited[r][c])
				continue;

			int areaSize = findArea(r, c);
			number_of_area++;

			if (areaSize > max_size_of_one_area)
				max_size_of_one_area = areaSize;
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
		{
			cout << visited[i][j] << " ";
		}
		cout << "\n";
	}

	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	cout << answer[0] << "< " << answer[1] << "\n";
	return answer;
}

int main() {
	solution(6, 4, { {1, 1, 1, 0},{1, 2, 2, 0},{1, 0, 0, 1},{0, 0, 0, 1},{0, 0, 0, 3},{0, 0, 0, 3} });
	return 0;
}