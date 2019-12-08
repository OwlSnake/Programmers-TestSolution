#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int M, N, H;
int box[101][101][101];
int dx[6] = { 0, 0, -1, 1, 0, 0 };
int dy[6] = { 1, -1, 0, 0, 0, 0 };
int dz[6] = { 0, 0, 0, 0, -1, 1 };

int leftTomato = 0, answer;

bool isInBound(int height, int row, int col) {
	if (height < 0 || row < 0 || col < 0 || height >= H || row >= N || col >= M)
		return false;
	return true;
}

void BFS(queue<tuple<int, int, int>> q) {
	if (leftTomato == 0) {
		answer = 0;
		return;
	}

	while (!q.empty()) {
		int h = get<0>(q.front());
		int r = get<1>(q.front());
		int c = get<2>(q.front());
		int days = box[h][r][c];
		q.pop();

		// Check neighbors
		for (int i = 0; i < 6; i++)
		{
			if (isInBound(h + dz[i], r + dx[i], c + dy[i]) && box[h + dz[i]][r + dx[i]][c + dy[i]] == 0) {
				q.push(make_tuple(h + dz[i], r + dx[i], c + dy[i]));
				box[h + dz[i]][r + dx[i]][c + dy[i]] = days + 1;
				leftTomato--;
			}
		}

		if (leftTomato == 0)
			answer = box[h][r][c] - 1;
	}

	if (leftTomato > 0)
		answer = -1;
}

void Solve()
{
	// Input
	cin >> M >> N >> H;
	queue<tuple<int, int, int>> tomatos;
	for (int k = 0; k < H; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++) {

				cin >> box[k][i][j];
				if (box[k][i][j] == 0)
					leftTomato++;
				if (box[k][i][j] == 1)
					tomatos.push(make_tuple(k, i, j));
			}
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