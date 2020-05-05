#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> costs) {
	int answer = 0;
	vector<bool> connected(n, 0);
	int connectCount = 0;
	const int INF = 1000000;

	vector<vector<int>> bridge(n);
	for (int r = 0; r < n; r++)
		bridge[r].resize(n, INF);

	for (auto cost : costs) {
		bridge[cost[0]][cost[1]] = cost[2];
		bridge[cost[1]][cost[0]] = cost[2];
	}

	// 0�� ������ ����
	// ��� ���� ����� ������
	connected[0] = true;
	connectCount = 1;
	while (connectCount < n) {
		// �߰� ������ ���� ���� ����� �ٸ� Ȯ��
		int minCost = INF;
		int minBegin, minEnd;
		for (int node = 0; node < n; node++) {
			if (!connected[node])
				continue;

			for (int i = 0; i < n; i++) {
				if (connected[i])
					continue;

				if (bridge[node][i] < minCost) {
					minCost = bridge[node][i];
					minBegin = node;
					minEnd = i;
				}
			}
		}
		// Ȯ���� �ٸ� �߰�
		connected[minEnd] = true;
		connectCount++;
		answer += minCost;
	}
	return answer;
}

void main() {
	cout << solution(4, { {0,1,1},{0,2,2},{1,2,5},{1,3,1},{2,3,8} });
	cout << endl;
	cout << solution(6, { {0, 1, 5},{0, 3, 2},{0, 4, 3},{1, 4, 1},{3, 4, 10},{1, 2, 2},{2, 5, 3},{4, 5, 4} });
	cout << endl;
}