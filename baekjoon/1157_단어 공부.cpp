#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	int max = 0;
	char result;
	cin >> s;
	int count[26] = { 0 };

	// count 배열에 각 알파벳이 사용된 횟수를 저장(대소문자 구분 없음)
	for (int i = 0; i < s.size(); i++) {
		if ('a' <= s[i] && s[i] <= 'z') {
			count[s[i] - 'a']++;
		}
		else {
			count[s[i] - 'A']++;
		}
	}

	// 가장 많이 사용된 알파벳을 찾는다(여럿일 때는 '?'출력)
	for (int i = 0; i < 26; i++) {
		if (count[i] > max) {
			max = count[i];
			result = (char)(i + (int)'A');
		}
		else if (count[i] == max && max != 0)
			result = '?';
	}
	cout << result;
	return 0;
}
