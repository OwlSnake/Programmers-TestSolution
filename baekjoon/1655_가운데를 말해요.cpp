#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> minHeap; // pop smallest
priority_queue<int, vector<int>, less<int>> maxHeap; // pop largest

void Solve()
{
	int N, t;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> t;
		if (minHeap.size() >= maxHeap.size())
			maxHeap.push(t);
		else
			minHeap.push(t);

		if (!minHeap.empty() && !maxHeap.empty() && minHeap.top() < maxHeap.top()) {
			int greaterTop = minHeap.top();
			int lessTop = maxHeap.top();
			minHeap.pop();
			maxHeap.pop();
			minHeap.push(lessTop);
			maxHeap.push(greaterTop);
		}
		cout << maxHeap.top() << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	Solve();
	return 0;
}