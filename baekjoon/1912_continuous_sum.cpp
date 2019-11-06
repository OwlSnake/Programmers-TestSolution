#include <iostream>
#include <algorithm>
using namespace std;

int N, num, answer = -1000;
int DP[100001] = { 0 };

int main() 
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> num;
		DP[i] = max(DP[i - 1] + num, num);
		answer = max(answer, DP[i]);
	}

	cout << answer;
	return 0;
}
