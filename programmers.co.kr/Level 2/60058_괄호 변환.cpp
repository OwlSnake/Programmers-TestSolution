#include <string>
#include <vector>

#include <iostream>

using namespace std;

// 2020.04.17
// https://programmers.co.kr/learn/courses/30/lessons/60058?language=cpp

bool balanced(string s) {
	int opened = 0;
	for (char c : s) {
		if (c == '(')
			opened++;
		else
			opened--;
	}
	return opened == 0;
}

bool correct(string s) {
	int opened = 0;
	for (char c : s) {
		if (c == '(')
			opened++;
		else
			opened--;

		if (opened < 0)
			return false;
	}
	return true;
}

string divString(string s) {
	string u, v;

	// 1.
	if (s.size() == 0)
		return "";

	if (correct(s))
		return s;

	// 2.
	for (int i = 2; i <= s.size(); i += 2) {
		if (balanced(s.substr(0, i))) {
			u = s.substr(0, i);
			v = s.substr(i);
			//cout << u << " // " << v << "\n";
			break;
		}
	}

	// 3.
	if (correct(u)) {
		u += divString(v);
		return u;
	}

	// 4-1.
	string temp = "(";
	// 4-2.
	temp += divString(v);
	// 4-3.
	temp += ")";
	// 4-4.
	string newU = u.substr(1, u.size() - 2);
	for (char& c : newU) {
		c = (c == '(') ? ')' : '(';
	}
	temp += newU;
	// 4-5
	cout <<temp << "\n";
	return temp;
}

string solution(string p) {
	string answer = "";

	if (p.size() == 0)
		return "";

	answer = divString(p);
	
	return answer;
}

int main() {
	solution("(()())()");
	solution(")(");
	solution("()))((()");
	return 0;
}