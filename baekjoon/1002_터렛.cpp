#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int result;
		double x1, y1, r1, x2, y2, r2;
		double dist;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		dist = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));

		if (x1 == x2 && y1 == y2) {
			if (r1 == r2)
				result = -1;
			else
				result = 0;
		}
		else {
			if (dist == r1 + r2 || dist == abs(r1 - r2))
				result = 1;
			else if (dist > r1 + r2)
				result = 0;
			else if (abs(r1 - r2) > dist)
				result = 0;
			else
				result = 2;
		}
		cout << result << '\n';
	}
	return 0;
}