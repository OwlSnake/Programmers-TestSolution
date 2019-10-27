#include <iostream>
#include <algorithm>
using namespace std;

int pt[301], ptDP[301];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int N;
	cin >> N;
	
	for (int i = 1; i <= N; i++)
		cin >> pt[i];

	ptDP[1] = pt[1];
	ptDP[2] = ptDP[1] + pt[2];
	ptDP[3] = max(ptDP[1] + pt[3], pt[2] + pt[3]);

	for (int i = 4; i <= N; i++)
		ptDP[i] = max(ptDP[i - 2] + pt[i], ptDP[i - 3] + pt[i - 1] + pt[i]);

	cout << ptDP[N];
	return 0;
}