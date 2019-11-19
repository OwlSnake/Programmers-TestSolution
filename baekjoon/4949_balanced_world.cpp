#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool CheckParenthesis(string s) {
	vector<char> parenthesis;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
			parenthesis.push_back('(');
		else if(s[i] == '[')
			parenthesis.push_back('[');
		else if (s[i] == ')') {
			if (parenthesis.size() > 0 && parenthesis.back() == '(')
				parenthesis.pop_back();
			else
				return false;
		}
		else if (s[i] == ']') {
			if (parenthesis.size() > 0 && parenthesis.back() == '[')
				parenthesis.pop_back();
			else
				return false;
		}
	}
	if (parenthesis.size() > 0)
		return false;
	return true;
}

void Solve()
{
	int N, answer = 0;
	string str;
	while (true)
	{
		string str;
		getline(cin, str);	
		if (str == ".")
			break;
		if (CheckParenthesis(str))
			cout << "yes\n";
		else
			cout << "no\n";
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	Solve();
	return 0;
}