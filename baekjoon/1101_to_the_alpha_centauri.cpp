#include <iostream>

using namespace std;

int main() {
	int t, dist;
	cin >> t;

	while (t--) {
		double x, y, dist;
		cin >> x >> y;
		dist = y - x;
		double i = 1;
		while (i * i < dist) {
			i++;
		}

		if (dist == (i - 1) * (i - 1))
			cout << 2 * (i - 1) - 1 << '\n';
		else if (dist <= (i - 1) * (i - 1) + ((i * i - (i - 1) * (i - 1)) / 2))
			cout << 2 * i - 2 << '\n';
		else
			cout << 2 * i - 1 << '\n';
	}
	
	return 0;
}
