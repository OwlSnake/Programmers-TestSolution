#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> solution(string msg) {
	unordered_map<string, int> dict;
	vector<int> answer;

	// dict 초기화
	int lastIndex = 26;
	for (int i = 1; i <= 26; i++) {
		string s;
		s += ('A' + i - 1);
		dict[s] = i;
	}

	while (msg.length() > 0) {
		// 가장 긴 문자열 찾기
		for (int len = msg.length(); len > 0; len--) {
			string w = msg.substr(0, len);

			if (dict.count(w)) {
				answer.push_back(dict[w]);
				msg.erase(msg.begin(), msg.begin() + len);

				// 메시지가 남아 있으면
				if (msg.length() > 0) {
					// w + c를 dict에 추가
					w += msg[0];
					lastIndex++;
					dict[w] = lastIndex;
				}
				break;
			}
		}
	}
	return answer;
}
void main() {
	//solution("KAKAO");
	//solution("TOBEORNOTTOBEORTOBEORNOT");
	solution("ABABABABABABABAB");
}