#include <iostream>
using namespace std;

int N, K, coin[10], answer = 0;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> coin[i];

	for (int i = N - 1; i >= 0; i--)
	{
		while (K >= coin[i]) {
			K -= coin[i];
			answer++;
		}
	}
	cout << answer;
	return 0;
}
