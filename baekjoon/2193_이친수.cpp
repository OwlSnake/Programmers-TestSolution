#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	long long answer[91] = { 0, 1, 1 };
	for (int i = 3; i <= N; i++)
		answer[i] = answer[i - 1] + answer[i - 2];

	cout << answer[N];
	return 0;
}

/*
1	1	1
2	1	10
3	2	100 + 101
4	3	1000 1010 + 1001
5	5	10100 10010 10000 + 10101 10001
6	8	101000 100100 100000 101010 100010 + 101001 100101 100001
7		10

*/