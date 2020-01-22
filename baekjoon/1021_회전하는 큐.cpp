#include <iostream>
#include <deque>
using namespace std;

void Solve()
{
	deque<int> q;
	int popTarget[50];
	int N, M, minCount = 0;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		q.push_back(i);

	for (int i = 0; i < M; i++)
		cin >> popTarget[i];

	for (int i = 0; i < M; i++)
	{
		// Already at front
		if (q.front() == popTarget[i]) {
			q.pop_front();
			continue;
		}

		int leftMoveCount = 0, rightMoveCount = 0;
		// Get leftMoveCount
		for (int j = 1; j < q.size(); j++){
			if (q[j] == popTarget[i]) {
				leftMoveCount = j;
				break;
			}
		}
		// Get rightMoveCount
		for (int j = 1; j < q.size(); j++)
		{
			if (q[q.size() - j] == popTarget[i]) {
				rightMoveCount = j;
				break;
			}
		}
		// Compare moveCount, and
		// Move next popTarget to front of deque
		if (leftMoveCount < rightMoveCount) {
			for (int i = 0; i < leftMoveCount; i++){
				q.push_back(q.front());
				q.pop_front();
			}
			minCount += leftMoveCount;
		}
		else {
			for (int i = 0; i < rightMoveCount; i++){
				q.push_front(q.back());
				q.pop_back();
			}
			minCount += rightMoveCount;
		}
		// Then pop
		q.pop_front();
	}

	cout << minCount;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	Solve();
	return 0;
}