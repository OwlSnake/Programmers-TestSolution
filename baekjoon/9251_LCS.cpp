#include <iostream>
#include <algorithm>

using namespace std;

string A, B;
int DP[1001][1001];

int main() 
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> A >> B;

	for (int i = 1; i <= A.size(); i++)
	{
		for (int j = 1; j <= B.size(); j++)
		{
			if (A[i-1] == B[j-1])
				DP[i][j] = DP[i - 1][j - 1] + 1;
			else
				DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
		}
	}
	
	cout << DP[A.size()][B.size()];
	return 0;
}
