#include <iostream>
using namespace std;

int backtracking(int n) {
	if (n == 0)
		return 1;

	int answer = 0;
	for (int i = 1; i <= 3; i++)
	{
		if (n >= 1)
			answer += backtracking(n - i);
	}
	return answer;
}

void solve() {
	int n;
	cin >> n;
	cout << backtracking(n) << '\n';
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
		solve();

	return 0;
}
