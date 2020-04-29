#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

#include <iostream>
using namespace std;

// https://programmers.co.kr/learn/courses/30/lessons/64065

vector<int> getSubArr(string s) {
	vector<int> result;

	int numBegin = 0, numEnd;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ',') {
			result.push_back(stoi(s.substr(numBegin, i - numBegin)));
			numEnd = i - 1;
			numBegin = i + 1;
		}
	}
	result.push_back(stoi(s.substr(numBegin)));

	return result;
}

bool compareLen(const vector<int>& a, const vector<int>& b) {
	return a.size() < b.size();
}

vector<int> solution(string s) {
	vector<int> answer;
	vector<vector<int>> list;

	int braceOpen = 0, braceClose;
	for (int i = 1; i < s.size() - 1; i++) {
		if (s[i] == '{') {
			braceOpen = i;
		}
		if (s[i] == '}') {
			braceClose = i;
			list.push_back(getSubArr(s.substr(braceOpen + 1, i - braceOpen - 1)));
		}
	}

	sort(list.begin(), list.end(), compareLen);

	unordered_map<int, int> counter;
	for (auto subArr : list) {
		for (int n : subArr) {
			if (counter[n] == 0) {
				answer.push_back(n);
				counter[n]++;
			}
		}
	}

	return answer;
}

void main() {
	solution("{{2},{2,1},{2,1,3},{2,1,3,4}}");
	solution("{{1,2,3},{2,1},{1,2,4,3},{2}}");
	solution("{{20,111},{111}}");
	solution("{{123}}");
	solution("{{4,2,3},{3},{2,3,4,1},{2,3}}");
}