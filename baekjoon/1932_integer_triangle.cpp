#include <iostream>
#include <algorithm>
using namespace std;

int tri[501][501];
int triDP[501][501];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int N, maxValue = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> tri[i][j];

			triDP[i][j] = max(triDP[i - 1][j - 1], triDP[i - 1][j]) + tri[i][j];
		}
	}

	for (int i = 1; i <= N; i++)
		maxValue = max(triDP[N][i], maxValue);

	cout << maxValue;
	return 0;
}