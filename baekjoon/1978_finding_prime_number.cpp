#include <iostream>
using namespace std;

bool IsPrime(int n) {
	if (n == 1)
		return false;
	if (n == 2 || n == 3)
		return true;

	for (int i = 2; i*i <= n; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

int main(){
	int N, t, count = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> t;
		count += IsPrime(t);
	}
	cout << count;
	return 0;
}