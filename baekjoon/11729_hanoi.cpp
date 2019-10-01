#include <iostream>
using namespace std;

void Move(int from, int to, int extra, int count) {
	if (count == 1) {
		cout << from << ' ' << to << '\n';
		return;
	}
	Move(from, extra, to, count - 1);
	Move(from, to, extra, 1);
	Move(extra, to, from, count - 1);
	return;
}

int main() {
	int n;
	cin >> n;

	int k = 1;
	for (int i = 1; i < n; i++)
		k = k * 2 + 1;
	cout << k << endl;

	Move(1, 3, 2, n);
	return 0;
}
