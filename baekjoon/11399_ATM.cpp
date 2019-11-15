#include <iostream>
#include <algorithm>
using namespace std;

int N, P[1001], answer = 0;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> P[i];
	sort(P, P + N);

	for (int i = 0; i < N - 1; i++) {
		P[i + 1] += P[i];
		answer += P[i];
	}
	answer += P[N - 1];
	cout << answer;
	return 0;
}
