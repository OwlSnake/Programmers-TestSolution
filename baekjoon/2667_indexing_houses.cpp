#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N;
int map[25][25];

bool isInBound(int row, int col) {
	if (row < 0 || col < 0)
		return false;
	if (row == N || col == N)
		return false;
	return true;
}

int DFS(int row, int col, int idx) {
	map[row][col] = idx;
	int houseCount = 1;

	// Check 4 neighbors
	if (isInBound(row + 1, col) && map[row + 1][col] == 1)
		houseCount += DFS(row + 1, col, idx);
	if (isInBound(row - 1, col) && map[row - 1][col] == 1)
		houseCount += DFS(row - 1, col, idx);
	if (isInBound(row, col + 1) && map[row ][col + 1] == 1)
		houseCount += DFS(row , col + 1, idx);
	if (isInBound(row, col - 1) && map[row ][col - 1] == 1)
		houseCount += DFS(row , col - 1, idx);
	return houseCount;
}

void Solve()
{
	// Input
	cin >> N;
	for (int i = 0; i < N; i++) {
		string line;
		cin >> line;
		for (int j = 0; j < N; j++)
			map[i][j] = line[j] - '0';
	}

	// Solve
	vector<int> houseCount;
	int curIdx = 2;
	int t;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 1) {
				t = DFS(i, j, curIdx);
				curIdx++;
				houseCount.push_back(t);
			}
		}
	}

	// Output
	sort(houseCount.begin(), houseCount.end());
	cout << houseCount.size() << '\n';
	for (int elem : houseCount)
		cout << elem << '\n';
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	Solve();
	return 0;
}