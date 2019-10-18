#include <iostream>
using namespace std;

void CheckRightAngle(int longest, int a, int b){
	if (longest * longest == a * a + b * b)
		cout << "right" << '\n';
	else
		cout << "wrong" << '\n';
}

int main() {
	while (true) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a + b + c == 0) break;

		if (a > b&& a > c)
			CheckRightAngle(a, b, c);
		else if (b > a&& b > c)
			CheckRightAngle(b, a, c);
		else
			CheckRightAngle(c, a, b);
	}
	return 0;
}