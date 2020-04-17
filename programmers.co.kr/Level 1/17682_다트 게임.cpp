#include <string>
#include <math.h>

// 2020.04.16
// https://programmers.co.kr/learn/courses/30/lessons/17682

using namespace std;

int solution(string dartResult) {
	int answer = 0;

	int point[3];
	int expo[3];
	int mul[3] = { 1, 1, 1 };

	int dartCount = -1;

	for (int i = 0; i < dartResult.size(); i++) {
		char c = dartResult[i];
		if ('0' <= c && c <= '9') {
			if (i > 0 && dartResult[i - 1] == '1') {
				point[dartCount] = 10;
			}
			else {
				dartCount++;
				point[dartCount] = c - '0';
			}
		}

		if (c == 'S')
			expo[dartCount] = 1;
		if (c == 'D')
			expo[dartCount] = 2;
		if (c == 'T')
			expo[dartCount] = 3;

		if (c == '*') {
			mul[dartCount] *= 2;
			if (dartCount > 0)
				mul[dartCount] *= 2;
		}
		if (c == '#') {
			mul[dartCount] *= -1;
		}
	}

	for (int i = 0; i < 3; i++) {
		answer += pow(point[i], expo[i]) * mul[i];
	}
	return answer;
}

void main() {
	solution("1D2S#10S");
	return;
}