#include <iostream>
using namespace std;

int cost[1001][3];
int minCost[1001][3];

int min(int a, int b, int c) {
	return (a < b && a < c) ? a : (b < c) ? b : c;
}
int min(int a, int b) {
	return (a < b) ? a : b;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int R, G, B;
		cin >> R >> G >> B;
		cost[i][0] = R;
		cost[i][1] = G;
		cost[i][2] = B;
	}

	for (int i = 1; i <= N; i++)
	{
		minCost[i][0] = min(minCost[i - 1][1], minCost[i - 1][2]) + cost[i][0];
		minCost[i][1] = min(minCost[i - 1][0], minCost[i - 1][2]) + cost[i][1];
		minCost[i][2] = min(minCost[i - 1][0], minCost[i - 1][1]) + cost[i][2];
	}

	cout << min(minCost[N][0], minCost[N][1], minCost[N][2]);
	return 0;
}