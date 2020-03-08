#include <iostream>
#include <algorithm>
using namespace std;

int N, M, H;
int minNewLine = 4;
int map[32][12] = { 0 };

void input() {
	cin >> N >> M >> H;
	int a, b;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		map[a][b] = 1;
	}
}

bool testMap() {
	bool valid = true;
	for (int col = 1; col <= N; col++)
	{
		int curCol = col;
		for (int row = 1; row <= H; row++)
		{
			if (map[row][curCol] == 1) {
				curCol++;
			}
			else if (map[row][curCol - 1] == 1) {
				curCol--;
			}
		}

		if (col != curCol) {
			valid = false;
			break;
		}
	}
	return valid;
}

void dfs(int row, int depth) {
	if (depth >= minNewLine) {
		return;
	}

	if (testMap()) {
		minNewLine = min(minNewLine, depth);
		return;
	}

	for (int r = row; r <= H; r++)
	{
		for (int c = 1; c <= N; c++)
		{
			if (map[r][c] == 0 && map[r][c-1] == 0 && map[r][c+1] == 0)
			{
				map[r][c] = 1;
				dfs(r, depth + 1);
				map[r][c] = 0;
			}
		}
	}
}

void solve() {
	dfs(1, 0);
	if (minNewLine > 3)
		minNewLine = -1;
}

int main() {
	input();
	solve();
	cout << minNewLine;
	return 0;
}