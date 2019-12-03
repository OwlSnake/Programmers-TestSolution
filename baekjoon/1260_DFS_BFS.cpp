#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, V;
int graph[1001][1001];
vector<int> DFSresult, BFSresult;

vector<int> DFSvisited(1001);
void DFS(int root) {
	DFSvisited[root] = 1;
	DFSresult.push_back(root);

	for (int i = 1; i <= N; i++) {
		if (graph[root][i] == 1 && DFSvisited[i] == 0)
			DFS(i);
	}
}

void BFS() {
	vector<int> visited(N + 1);
	queue<int> queue;

	queue.push(V);
	visited[V] = 1;

	while (!queue.empty()) {
		int cur = queue.front();
		queue.pop();
		BFSresult.push_back(cur);

		for (int i = 1; i <= N; i++) {
			if (graph[cur][i] == 1 && visited[i] == 0) {
				queue.push(i);
				visited[i] = 1;
			}
		}
	}
}

void Solve()
{
	// Input
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++)
	{
		int n1, n2;
		cin >> n1 >> n2;
		graph[n1][n2] = 1;
		graph[n2][n1] = 1;
	}

	DFS(V);
	BFS();

	// Output
	for (int elem : DFSresult)
		cout << elem << ' ';
	cout << '\n';
	for (int elem : BFSresult)
		cout << elem << ' ';

}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	Solve();
	return 0;
}