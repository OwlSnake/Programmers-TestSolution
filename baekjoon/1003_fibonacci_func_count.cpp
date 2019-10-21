#include <iostream>
using namespace std;

long long fib[50] = { 0, 1 ,1 };

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T, N;
	cin >> T;

	for (int j = 0; j < T; j++)
	{
		cin >> N;
		if (N == 0) {
			cout << "1 0\n";
			continue;
		}
		if (N == 1) {
			cout << "0 1\n";
			continue;
		}

		for (int i = 1; i <= N; i++)
			fib[i + 1] = fib[i] + fib[i - 1];

		cout << fib[N - 1] << ' ' << fib[N] << '\n';
	}
	return 0;
}