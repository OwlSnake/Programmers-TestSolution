#include <iostream>
#include <vector>
using namespace std;

bool CheckParenthesis(string s) {
	int openedP = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
			openedP++;
		else			
			openedP--;

		if (openedP < 0)
			return false;
	}
	if (openedP != 0)
		return false;
	return true;
}

void Solve()
{
	int N, answer = 0;
	vector<int> stack;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string PS;
		cin >> PS;
		if (CheckParenthesis(PS))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	Solve();
	return 0;
}