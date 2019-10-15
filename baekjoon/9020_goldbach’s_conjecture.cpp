#include <iostream>
#include <vector>
using namespace std;


int main() {
	const int MAX_PRIME = 10000;
	int T;
	
	vector<bool> isPrime(MAX_PRIME, true);
	isPrime[1] = false;
	for (int i = 2; i * i < MAX_PRIME; i++) {
		if (isPrime[i])
			for (int j = i * 2; j < MAX_PRIME; j += i)
				isPrime[j] = false;
	}

	cin >> T;
	while (T--) {
		int n, max_i = 0;
		cin >> n;

		for (int i = 2; i <= n / 2; i++) {
			if (isPrime[i] && isPrime[n - i]) {
				if (i > max_i)
					max_i = i;
			}
		}
		cout << max_i << ' ' << n - max_i << '\n';
	}

	return 0;
}