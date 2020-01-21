#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	long long answer[46] = { 0, 1, 1 };
	for (int i = 3; i <= N; i++)
		answer[i] = answer[i - 1] + answer[i - 2];

	cout << answer[N];
	return 0;
}