#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, K, answer;;
vector<int> arr(100001);

void BFS() {
	queue<int> q;
	q.push(N);
	arr[N] = 1;

	while (!q.empty()) {
		int pos = q.front();
		q.pop();

		if (pos == K) {
			answer = arr[pos] - 1;
			return;
		}

		if (pos > 0 && arr[pos - 1] == 0) {
			q.push(pos - 1);
			arr[pos - 1] = arr[pos] + 1;
		}
		if (pos < 100000 && arr[pos + 1] == 0) {
			q.push(pos + 1);
			arr[pos + 1] = arr[pos] + 1;
		}
		if (pos * 2 <= 100000 && arr[pos * 2] == 0) {
			q.push(pos * 2);
			arr[pos * 2] = arr[pos] + 1;
		}
	}
}

void Solve()
{
	// Input
	cin >> N >> K;

	// Solve
	BFS();

	// Output
	cout << answer;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	Solve();
	return 0;
}