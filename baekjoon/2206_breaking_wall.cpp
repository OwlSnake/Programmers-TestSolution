#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int N, M;
int map[1001][1001];
bool visited[1001][1001][2];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

bool isInMap(int row, int col) {
	if (row < 0 || col < 0 || row >= N || col >= M)
		return false;
	return true;
}

int BFS() {
	queue<tuple<int, int, int, int>> q;
	q.push(make_tuple(0, 0, 0, 1));
	visited[0][0][0] = true;

	// Start searching
	while (!q.empty()) {
		int row = get<0>(q.front());
		int col = get<1>(q.front());
		int brokenWall = get<2>(q.front());
		int dist = get<3>(q.front());
		q.pop();

		if (row == N - 1 && col == M - 1)
			return dist;

		// Check neighbors
		for (int i = 0; i < 4; i++)
		{
			int nextRow = row + dx[i];
			int nextCol = col + dy[i];
			if (!isInMap(nextRow, nextCol))
				continue;

			if (map[nextRow][nextCol] == 0 && !visited[nextRow][nextCol][brokenWall]) {
				q.push(make_tuple(nextRow, nextCol, brokenWall, dist + 1));
				visited[nextRow][nextCol][brokenWall] = true;
			}
			// Can break wall
			else if (map[nextRow][nextCol] == -1 && brokenWall == 0) {
				q.push(make_tuple(nextRow, nextCol, 1, dist + 1));
				visited[nextRow][nextCol][brokenWall] = true;
			}
		}
	}

	return -1;
}

void Solve()
{
	// Input
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string line;
		cin >> line;
		for (int j = 0; j < M; j++) {
			if (line[j] == '1')
				map[i][j] = -1;
			else
				map[i][j] = 0;
		}
	}

	// Solve
	cout << BFS();
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	Solve();
	return 0;
}