#include <vector>
#include <iostream>

using namespace std;

int MOD = 20170805;

int rRoute[501][501];
int dRoute[501][501];

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
	int answer = 0;

	memset(rRoute, 0, sizeof(rRoute));
	memset(dRoute, 0, sizeof(rRoute));
	rRoute[1][1] = 1;
	dRoute[1][1] = 1;

	for (int r = 1; r <= m; r++) {
		for (int c = 1; c <= n; c++) {

			if (city_map[r - 1][c - 1] == 2) {
				rRoute[r][c] = rRoute[r][c - 1];
				dRoute[r][c] = dRoute[r - 1][c];
			}
			else if (city_map[r - 1][c - 1] == 1) {
				rRoute[r][c] = 0;
				dRoute[r][c] = 0;
			}
			else {
				rRoute[r][c] += (rRoute[r][c - 1] + dRoute[r - 1][c]) % MOD;
				dRoute[r][c] += (rRoute[r][c - 1] + dRoute[r - 1][c]) % MOD;
			}
		}
	}

	for (int r = 1; r <= m; r++) {
		for (int c = 1; c <= n; c++) {
			cout << rRoute[r][c] + dRoute[r][c] << "\t";
		}
		cout << endl;
	}

	return rRoute[m][n];
}

void main() {
	cout << solution(3, 3, { {0,0,0},{0,0,0},{0,0,0} }) << endl;
	cout << solution(3, 6, { {0,2,0,0,0,2},{0,0,2,0,1,0},{1,0,0,2,2,0} }) << endl;
}