#include <iostream>

using namespace std;

int main() {
	const int HEIGHT = 15, WIDTH = 14;
	int apt[HEIGHT][WIDTH];
	int T;
	cin >> T;

	for (int i = 0; i < WIDTH; i++)
		apt[0][i] = i+1;

	for (int i = 1; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			apt[i][j] = 0;
			for (int k = 0; k <= j; k++)
				apt[i][j] += apt[i - 1][k];
		}
	}

	while (T--) {
		int k, n;
		cin >> k >> n;
		cout << apt[k][n-1] << '\n';
	}
	return 0;
}	
 