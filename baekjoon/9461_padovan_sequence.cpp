#include <iostream>
using namespace std;

long long fib[101] = { 0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9 };

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T, N;
	cin >> T;

	for (int i = 11; i <= 100; i++)
		fib[i] = (fib[i - 2] + fib[i - 3]);

	for (int i = 0; i < T; i++)
	{
		cin >> N;
		cout << fib[N] << '\n';
	}
	return 0;
}