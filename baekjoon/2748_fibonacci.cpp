#include <iostream>
using namespace std;

long long fib[100] = { 0, 1, 1 };

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) 
		fib[i + 1] = fib[i] + fib[i - 1];
	
	cout << fib[N];

	return 0;
}