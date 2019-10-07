#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
	int n, count = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string input;
		bool isGroupWord = true;
		unordered_map<char, int> hashTable;
		
		cin >> input;

		// 이어서 나오는 문자 제거
		for (int j = 0; j < input.size(); j++){
			if (input[j] == input[j + 1]) {
				input.erase(j, 1);
				j--;
			}
		}

		// 중복되는 문자가 있는 지 확인
		for (int j = 0; j < input.size(); j++)
		{
			if (hashTable.count(input[j]) == 0)
				hashTable[input[j]] = 1;
			else {
				isGroupWord = false;
				break;
			}
		}
		count += isGroupWord;
	}

	cout << count;
	return 0;
}
