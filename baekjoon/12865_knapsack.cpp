#include <iostream>
using namespace std;

int N, max_W;
int DP[101][100001];
int w[101], v[101];

int max(int a, int b) {
	return (a > b) ? a : b;
}

int main() 
{
	// 입력
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> max_W;
	for (int i = 1; i <= N; i++)
		cin >> w[i] >> v[i];

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= max_W; j++)
		{
			if (w[i] > j)
				DP[i][j] = DP[i - 1][j];
			else
				DP[i][j] = max(DP[i - 1][j - w[i]] + v[i], DP[i - 1][j]);
		}
	}

	// 출력
	cout << DP[N][max_W];
	return 0;
}
