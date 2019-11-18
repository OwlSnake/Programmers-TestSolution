#include <iostream>
#include <string>
using namespace std;

void Solve()
{
	string exp, num;
	cin >> exp;

	int answer = 0;
	bool IsAfterMinus = false;
	for (int i = 0; i <= exp.length(); i++)
	{
		if (exp[i] == '+' || exp[i] == '-' || exp[i] == '\0') {
			if (IsAfterMinus)
				answer -= stoi(num);
			else
				answer += stoi(num);
			num = "";
			if (exp[i] == '-')
				IsAfterMinus = true;
		}
		else
			num += exp[i];
	}
	cout << answer;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	Solve();
	return 0;
}