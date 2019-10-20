#include <iostream>
#define INT_MAX 2147483647

using namespace std;

int GetDivsum(int N) {
	int result = N;
	while (N > 0) {
		result += N % 10;
		N /= 10;
	}
	return result;
}

int main() {
	int N, min_constructor = INT_MAX;
	cin >> N;

	for (int i = 1; i < N; i++) {
		int temp = GetDivsum(i);
		if (temp == N) {
			if (i < min_constructor)
				min_constructor = i;
		}
	}

	if (min_constructor == INT_MAX)
		cout << 0;
	else
		cout << min_constructor;

	return 0;
}
 