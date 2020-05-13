#include <string>
#include <vector>
#include <iostream>

using namespace std;


// n진법 문자열로 변경
string convert(int num, int n) {
	const string toHexChar = "0123456789ABCDEF";
	string result = "";
	vector<char> stack;

	if (num == 0)
		return "0";

	while (num > 0) {
		stack.push_back(toHexChar[num % n]);
		num /= n;
		cout << stack.back() << endl;
	}

	while (stack.size() > 0) {
		result += stack.back();
		stack.pop_back();
	}
	return result;
}

string solution(int n, int t, int m, int p) {
	string game = "";
	string answer = "";

	// m명이 t번째 말할 때 까지 게임 진행
	int nextNum = 0;
	while (game.length() < t * m) {
		game += convert(nextNum, n);
		nextNum++;
	}

	// p번째 사람이 말할 목록 확인
	for (int i = 0; i < t; i++){
		answer += game[(i * m) + (p - 1)];
	}
	return answer;
}

void main() {
	cout << solution(2, 4, 2, 1) << endl;
	cout << solution(16, 16, 2, 1) << endl;
	cout << solution(16, 16, 2, 2) << endl;
}