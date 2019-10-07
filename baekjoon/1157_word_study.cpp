#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	int max = 0;
	char result;
	cin >> s;
	int count[26] = { 0 };

	// count �迭�� �� ���ĺ��� ���� Ƚ���� ����(��ҹ��� ���� ����)
	for (int i = 0; i < s.size(); i++) {
		if ('a' <= s[i] && s[i] <= 'z') {
			count[s[i] - 'a']++;
		}
		else {
			count[s[i] - 'A']++;
		}
	}

	// ���� ���� ���� ���ĺ��� ã�´�(������ ���� '?'���)
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
