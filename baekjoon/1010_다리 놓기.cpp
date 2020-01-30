#include <iostream>
using namespace std;

int main() {
	int T, arr[31][31] = { 0 };
	cin >> T;

	for (int i = 1; i <= 30; i++)
		arr[1][i] = i;

	for (int i = 2; i <= 30; i++)
	{
		for (int j = i; j <= 30; j++) {
			int sum = 0;
			for (int k = i - 1; k <= j-1; k++) {
				sum += arr[i-1][k];
			}
			arr[i][j] = sum;
		}
	}

	while (T--) {
		int N, M;
		cin >> N >> M;
		cout << arr[N][M] << '\n';
	}

	return 0;
}