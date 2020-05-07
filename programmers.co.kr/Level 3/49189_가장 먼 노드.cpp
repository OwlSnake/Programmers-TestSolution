#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
	vector<vector<int>> link(n + 1, vector<int>(n + 1, 0));

	for (auto e : edge) {
		link[e[0]][e[1]] = 1;
		link[e[1]][e[0]] = 1;
	}

	vector<int> nodeDist(n + 1, 0);
	vector<bool> visited(n + 1, 0);
	queue<int> q;
	int maxDist = 0;

	q.push(1);
	visited[1] = true;

	// BFS
	while (!q.empty()) {
		int node = q.front();
		q.pop();

		for (int i = 1; i <= n; i++) {
			if (link[node][i] && !visited[i]) {
				cout << "push " << i << endl;
				q.push(i);
				visited[i] = true;
				nodeDist[i] = nodeDist[node] + 1;

				if (maxDist < nodeDist[i])
					maxDist = nodeDist[i];
			}
		}
	}

	int maxCount = 0;
	for (int dist : nodeDist) {
		cout << "dist : " << dist << endl;
		if (dist == maxDist)
			maxCount++;
	}

	return maxCount;
}

void main() {
	cout << solution(6, { {3, 6},{4,3},{3,2},{1,3},{1,2},{2,4},{5,2} }) << endl;
}