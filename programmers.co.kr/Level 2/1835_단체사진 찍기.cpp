#include <string>
#include <vector>
#include <algorithm>

#include <iostream>
using namespace std;

int solution(int n, vector<string> data) {
	int answer = 0;
	char line[8] = { 'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T' };

	do {
		bool validLine = true;
		for (string s : data) {
			char left = s[0];
			char right = s[2];
			char op = s[3];
			int dist = s[4] - '0';
			int lIndex, rIndex;
			
			for (int i = 0; i < 8; i++) {
				if (line[i] == left)
					lIndex = i;
				if (line[i] == right)
					rIndex = i;
			}

			if (op == '=') {
				if (abs(lIndex - rIndex) - 1 != dist) {
					validLine = false;
					break;
				}
			}
			if (op == '<') {
				if (abs(lIndex - rIndex) - 1 >= dist) {
					validLine = false;
					break;
				}
			}
			if (op == '>') {
				if (abs(lIndex - rIndex) - 1 <= dist) {
					validLine = false;
					break;
				}
			}
		}

		if (validLine) {
			answer++;
		}

	} while (next_permutation(line, line + 8));
	
	return answer;
}

int main() {
	solution(2, { "N~F=0", "R~T>2" });
	//solution(2, { "M~C<2", "C~M>1" });
	return 0;
}