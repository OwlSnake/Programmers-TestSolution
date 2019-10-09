#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	if (n == 4 || n == 7) {
		cout << -1;
		return 0;
	}

	switch (n % 5) {
	case 0:
		cout << n / 5;
		break;
	case 1:
		// 6, 11 ...
		cout << (n / 5) + 1;
		break;
	case 2:
		// 12, 17...
		cout << n / 5 + 2;
		break;
	case 3:
		// 8, 13, 18...
		cout << (n / 5) + 1;
		break;
	case 4:
		// 9, 14, 21...
		cout << (n / 5) + 2;
		break;
	}

	return 0;
}
