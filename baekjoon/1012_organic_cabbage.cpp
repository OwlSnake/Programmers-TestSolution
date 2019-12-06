#include <iostream>
using namespace std;

int map[50][50];
int M, N;

bool IsInBound(int row, int col) {
	if (row < 0 || col < 0 || row >= N || col >= M)
		return false;
	return true;
}

void DFS(int row, int col) {
	map[row][col] = 0;

	// Check 4 neighbors
	if (IsInBound(row + 1, col) && map[row + 1][col] == 1)
		DFS(row + 1, col);
	if (IsInBound(row - 1, col) && map[row - 1][col] == 1)
		DFS(row - 1, col);
	if (IsInBound(row, col + 1) && map[row ][col + 1] == 1)
		DFS(row , col + 1);
	if (IsInBound(row, col - 1) && map[row ][col - 1] == 1)
		DFS(row , col - 1);
}


void PrintArray(int row, int col) {
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			cout << map[i][j] << ' ';

		cout << '\n';
	}
}

void Solve()
{
	// Input
	int K, result = 0;
	cin >> M >> N >> K;
	for (int i = 0; i < K; i++)
	{
		int x, y;
		cin >> x >> y;
		map[y][x] = 1;
	}

	// Solve
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 1) {
				result++;
				DFS(i, j);
			}
		}
	}

	// Output
	cout << result << '\n';

}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	while(T--)
		Solve();
	return 0;
}