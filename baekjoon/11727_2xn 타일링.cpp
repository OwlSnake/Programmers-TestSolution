#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	int answer[1001] = { 0, 1, 2 };
	for (int i = 3; i <= N; i++)
		answer[i] = (answer[i - 1] + answer[i - 2]) % 10007;

	cout << answer[N];
	return 0;
}