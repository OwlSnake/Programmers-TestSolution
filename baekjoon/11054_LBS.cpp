#include <iostream>
#include <algorithm>
using namespace std;

int list[1001];
int DP_asc[1001];
int DP_dsc[1001];

int main() 
{
	ios::sync_with_stdio(0); cin.tie(0);
	int N, answer = 0;
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> list[i];

	DP_asc[1] = 1;
	for (int i = 2; i <= N; i++)
	{
		int maxLenAsc = 0;
		for (int j = 1; j < i; j++)
		{
			if (list[i] > list[j])
				maxLenAsc = max(maxLenAsc, DP_asc[j]);
		}
		DP_asc[i] = maxLenAsc + 1;
	}

	DP_dsc[N] = 1;
	for (int i = N; i >= 1; i--)
	{
		int maxLenDsc = 0;
		for (int j = N; j > i; j--)
		{
			if (list[i] > list[j])
				maxLenDsc = max(maxLenDsc, DP_dsc[j]);
		}
		DP_dsc[i] = maxLenDsc + 1;
	}
	
	// i까지의 증가 수열 + i부터의 감소 수열 - 1
	for (int i = 1; i <= N; i++)
		answer = max(answer, DP_asc[i] + DP_dsc[i] - 1);

	cout << answer;
	return 0;
}
