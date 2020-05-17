#include <algorithm>
using namespace std;

// 2020.04.17
// https://programmers.co.kr/learn/courses/30/lessons/62048?language=cpp

long long gcd(long long a, long long b) {
	if (a % b == 0)
		return b;
	return gcd(b, a % b);
}

long long solution(int width, int height)
{
	long long w = width, h = height;
	long long answer = w * h;
	long long broken = w + h - gcd(w, h);
	
	return answer - broken;
}


int main() {
	solution(8, 12);
	solution(100000000, 1);
	solution(5, 5);
	return 0;
}