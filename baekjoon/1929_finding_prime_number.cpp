#include <iostream>
using namespace std;

bool IsPrime(int n) {
	if (n == 2 || n == 3)
		return true;
	if (n == 1 || n % 2 == 0 || n % 3 == 0)
		return false;

	for (int i = 5; i * i <= n; i += 6)
	{
		if (n % i == 0 || n % (i + 2) == 0)
			return false;
	}
	return true;
}

int main() {
	int N, M;
	cin >> N >> M;

	for (int i = N; i <= M; i++)
	{
		if (IsPrime(i))
			cout << i << '\n';
	}
	return 0;
}