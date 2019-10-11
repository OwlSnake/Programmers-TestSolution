#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int H, W, N;
		cin >> H >> W >> N;

		if (N % H == 0) 
			printf("%d%02d\n", H, N / H);
		else
			printf("%d%02d\n", N % H, N / H + 1);
	}
	return 0;
}	
 