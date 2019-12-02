#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int graph[101][101];
int answer = 0;

void BFS() {
	vector<int> visited(N + 1);
	queue<int> queue;

	queue.push(1);
	visited[1] = 1;

	while (!queue.empty()) {
		int cur = queue.front();
		queue.pop();

		for (int i = 1; i <= N; i++) {
			if (graph[cur][i] == 1 && visited[i] == 0) {
				queue.push(i);
				visited[i] = 1;
				answer++;
			}
		}
	}
}

void Solve()
{
	// Input
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int n1, n2;
		cin >> n1 >> n2;
		graph[n1][n2] = 1;
		graph[n2][n1] = 1;
	}

	// Solve
	BFS();

	// Output
	cout << answer;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	Solve();
	return 0;
}