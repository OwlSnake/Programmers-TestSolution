#include <iostream>
#include <queue>
using namespace std;

int N, M;
int map[101][101];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

bool isInBound(int row, int col) {
	if (row < 0 || col < 0 || row >= N || col >= M)
		return false;
	return true;
}

void BFS(int row, int col) {
	queue<pair<int, int>> q;
	q.push(make_pair(row, col));

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		int d = map[r][c];
		q.pop();

		if (r == N - 1 && c == M - 1)
			break;

		// Check neighbors
		for (int i = 0; i < 4; i++)
		{
			if (map[r + dx[i]][c + dy[i]] == 1 && isInBound(r + dx[i], c + dy[i])) {
				q.push(make_pair(r + dx[i], c + dy[i]));
				map[r + dx[i]][c + dy[i]] = d + 1;
			}
		}
	}
	map[0][0] = 1;
}

void Solve()
{
	// Input
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string line;
		cin >> line;
		for (int j = 0; j < M; j++)
			map[i][j] = line[j] - '0';
	}
	
	// Solve
	BFS(0, 0);

	// Output
	cout << map[N-1][M-1];
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	Solve();
	return 0;
}