#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, pack[1001], dp[1001] = { 0 };
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> pack[i];

	for (int i = 1; i <= N; i++)
	{
		int mx = pack[i];
		for (int j = 1; j <= i/2; j++)
			mx = max(dp[i-j] + dp[j], mx);
		
		dp[i] = mx;
	}
	cout << dp[N];

	return 0;
}
