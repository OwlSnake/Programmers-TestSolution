#include <iostream>
#include <vector>
using namespace std;

void Solve()
{
	int N, t;
	cin >> N;
	vector<int> seq(N), NGE(N), stack;
	for (int i = 0; i < N; i++)
		cin >> seq[i];

	for (int i = N - 1; i >= 0; i--)
	{
		while (!stack.empty() && stack.back() <= seq[i])
			stack.pop_back();

		if (stack.empty())
			NGE[i] = -1;
		else
			NGE[i] = stack.back();

		stack.push_back(seq[i]);
	}

	for (int i = 0; i < N; i++)
		cout << NGE[i] << ' ';
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	Solve();
	return 0;
}