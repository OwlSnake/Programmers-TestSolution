#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void Solve()
{
	int N;
	cin >> N;
	vector<vector<int>> tree(N + 1);
	vector<int> parent(N + 1);
	vector<bool> visited(N + 1);

	// Input
	for (int i = 0; i < N - 1; i++)
	{
		int n1, n2;
		cin >> n1 >> n2;
		tree[n1].push_back(n2);
		tree[n2].push_back(n1);
	}

	// BFS
	visited[1] = true;
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int curNode = q.front();
		q.pop();
		for (int child : tree[curNode])
		{
			if (!visited[child])
			{
				q.push(child);
				parent[child] = curNode;
				visited[child] = true;
			}
		}
	}

	// Output
	for (int i = 2; i <= N; i++)
		cout << parent[i] << '\n';
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	Solve();
	return 0;
}