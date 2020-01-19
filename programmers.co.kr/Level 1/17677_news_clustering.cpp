#include <string>
#include <iostream>
#include <unordered_map>;
#include <algorithm>
using namespace std;

bool IsLowerChar(char c) {
	return (c >= 'a' && c <= 'z');
}

string ToLowerCase(string str) {
	const int diff = 'A' - 'a';

	for (int i = 0; i < str.length(); i++)
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] -= diff;
	return str;
}

int solution(string str1, string str2) {

	str1 = ToLowerCase(str1);
	str2 = ToLowerCase(str2);
	
	unordered_map<string, int> map1, map2;

	for (int i = 0; i < str1.length(); i++) {
		if (IsLowerChar(str1[i]) && IsLowerChar(str1[i + 1])) {
			string elem = str1.substr(i, 2);
			map1[elem]++;
		}
	}
	for (int i = 0; i < str2.length(); i++) {
		if (IsLowerChar(str2[i]) && IsLowerChar(str2[i + 1])) {
			string elem = str2.substr(i, 2);
			map2[elem]++;
		}
	}

	int mapSize1 = 0, mapSize2 = 0;
	int intersectionCount = 0, unionCount = 0;

	for (auto pair : map1)
		mapSize1 += pair.second;
	for (auto pair : map2)
		mapSize2 += pair.second;

	for (auto pair : map1) {
		intersectionCount += min(pair.second, map2[pair.first]);
	}

	unionCount = mapSize1 + mapSize2 - intersectionCount;

	if (unionCount <= 0)
		return 65536;

	float similarity = ((float)intersectionCount / unionCount) * 65536;
	return (int)similarity;
}

void main() {
	string a, b;
	getline(cin, a);
	getline(cin, b);
	cout << solution(a, b);
}
