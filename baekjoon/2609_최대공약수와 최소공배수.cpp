#include <iostream>
using namespace std;

int main() {
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
	lcm  /= lcd;

	cout << lcd << '\n' << lcm;

	return 0;
}