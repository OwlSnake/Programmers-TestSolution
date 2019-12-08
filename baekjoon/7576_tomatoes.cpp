#include <iostream>
#include <queue>
using namespace std;

int M, N;
int box[1001][1001];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

int leftTomato = 0, answer;

bool isInBound(int row, int col) {
	if (row < 0 || col < 0 || row >= N || col >= M)
		return false;
	return true;
}

void BFS(queue<pair<int, int>> q) {
	if (leftTomato == 0) {
		answer = 0;
		return;
	}

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		int days = box[r][c];
		q.pop();

		// Check neighbors
		for (int i = 0; i < 4; i++)
		{
			if (box[r + dx[i]][c + dy[i]] == 0 && isInBound(r + dx[i], c + dy[i])) {
				q.push(make_pair(r + dx[i], c + dy[i]));
				box[r + dx[i]][c + dy[i]] = days + 1;
				leftTomato--;
			}
		}

		if (leftTomato == 0)
			answer = box[r][c] - 1;
	}

	if (leftTomato > 0)
		answer = -1;
}

void Solve()
{
	// Input
	cin >> M >> N;
	queue<pair<int, int>> tomatos;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++) {
			cin >> box[i][j];
			if (box[i][j] == 0)
				leftTomato++;
			if (box[i][j] == 1)
				tomatos.push(make_pair(i, j));
		}
	}
	
	// Solve
	BFS(tomatos);

	// Output
	cout << answer;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	Solve();
	return 0;
}