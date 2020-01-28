#include <iostream>
using namespace std;

void solve() {

	int a, b, t;
	int lcm, lcd;
	cin >> a >> b;
	lcm = a * b;

	while (b != 0) {
		t = a % b;
		a = b;
		b = t;
	}
	lcd = a;
	lcm /= lcd;

	cout << lcm << '\n';
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
		solve();

	return 0;
}
