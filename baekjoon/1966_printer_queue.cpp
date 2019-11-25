#include <iostream>
#include <queue>
using namespace std;

void Solve()
{
	int N, M, printCount = 0;
	cin >> N >> M;

	queue<int> q;
	priority_queue<int> pq;
	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		q.push(t);
		pq.push(t);
	}

	while (!q.empty()) {
		while (q.front() < pq.top()) {
			q.push(q.front());
			q.pop();
			
			M = (M == 0) ? q.size() - 1 : M - 1;
		}
		if (M == 0) {
			cout << ++printCount << '\n';
			break;
		}	
		else {
			q.pop();
			pq.pop();
			M--;
			printCount++;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
		Solve();
	return 0;
}