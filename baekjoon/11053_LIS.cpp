#include <iostream>
#include <algorithm>
using namespace std;

int list[1001];
int DP[1001];

int main() 
{
	ios::sync_with_stdio(0); cin.tie(0);
	int N, answer = 0;
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> list[i];

	DP[1] = 1;
	for (int i = 2; i <= N; i++)
	{
		int max_len = 0;
		for (int j = 1; j < i; j++)
		{
			if (list[i] > list[j])
				max_len = max(max_len, DP[j]);
		}
		DP[i] = max_len + 1;
	}
	
	for (int i = 1; i <= N; i++)
		answer = max(answer, DP[i]);
	cout << answer;
	return 0;
}
