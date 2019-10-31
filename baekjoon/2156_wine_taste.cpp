#include <iostream>
#include <algorithm>
using namespace std;

int drink[10001];
int DP[10001];

int max(int a, int b, int c) {
	return max(a, max(b, c));
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> drink[i];

	DP[0] = 0;
	DP[1] = drink[1];
	DP[2] = drink[1] + drink[2];
	for (int i = 3; i <= N; i++)
		DP[i] = max(DP[i - 3] + drink[i - 1] + drink[i], DP[i - 2] + drink[i], DP[i - 1]);

	cout << DP[N];
	return 0;
}
