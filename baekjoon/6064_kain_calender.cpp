#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int M, N, x, y, k = -1;
		cin >> M >> N >> x >> y;

		for (int i = 0; i < N; i++)
		{
			int yearCount = x + i * M;
			if (yearCount % N == y || N == y && yearCount % N == 0) {
				k = yearCount;
				break;
			}
		}

		cout << k << '\n';

	}
	return 0;
}	
 