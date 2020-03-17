#include <iostream>
using namespace std;

int fib[1000001] = { 0, 1, 1, 3, 5 };

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int N;
	cin >> N;
	for (int i = 4; i < N; i++)
		fib[i + 1] = (fib[i] + fib[i - 1]) % 15746;

	cout << fib[N];
}