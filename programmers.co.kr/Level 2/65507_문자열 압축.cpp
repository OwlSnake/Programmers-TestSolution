#include <string>
#include <vector>

#include <iostream>
using namespace std;

// 2020.04.17
// https://programmers.co.kr/learn/courses/30/lessons/60057/solution_groups?language=cpp

string compress(string s, int n) {
	vector<string> subs;
	string result = "";
	int compCount = 1;
	// 문자열 쪼개기
	for (int i = 0; i < s.length(); i += n) {
		subs.push_back(s.substr(i, n));
	}

	// 두개씩 비교하면서 압축
	for (int i = 1; i < subs.size(); i++) {
		if (subs[i] != subs[i-1]) {
			if (compCount > 1) {
				result += to_string(compCount);
				compCount = 1;
			}
			result += subs[i - 1];
		}
		else {
			compCount++;
		}
	}
	if (compCount > 1) {
		result += to_string(compCount);
	}
	result += subs[subs.size() - 1];
	
	cout << result << "\n";
	return result;
}

int solution(string s) {
	int answer = s.length();
	// 1부터 길이/2까지 모든 경우의 수 확인
	for (int i = 1; i <= s.length() / 2; i++) {
		string comp = compress(s, i);
		if (comp.length() < answer)
			answer = comp.length();
	}
	cout << answer << "\n\n";
	return answer;
}

int main() {
	solution("aabbaccc");
	solution("ababcdcdababcdcd");
	solution("abcabcdede");
	solution("abcabcabcabcdededededede");
	solution("xababcdcdababcdcd");
	return 0;
}