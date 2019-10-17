#include <iostream>
using namespace std;

int count_arr[10001];

int main() {
	int N, t;
	cin >> N;
	for (int i = 0; i < N; i++){
		scanf("%d", &t);
		count_arr[t]++;
	}


	for (int i = 1; i <= 10000; i++)
		for (int j = 0; j < count_arr[i]; j++)
			printf("%d\n", i);

	return 0;
}