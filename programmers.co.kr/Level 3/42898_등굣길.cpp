#include <string>
#include <vector>

using namespace std;

int map[101][101] = { 0 };
int dp[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {

	for (vector<int> p : puddles) {
		map[p[0]][p[1]] = -1;
	}

	for (int r = 1; r <= n; r++) {
		for (int c = 1; c <= m; c++) {
			if (map[r][c] == -1) {
				dp[r][c] = 0;
				continue;
			}
			dp[r][c] = (dp[r - 1][c] + dp[r][c - 1]) % 1000000007;

		}
	}

	return dp[n][m];
}