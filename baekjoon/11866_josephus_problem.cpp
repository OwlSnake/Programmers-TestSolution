#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void Solve()
{
	int N, K, step = 1;
	cin >> N >> K;
	queue<int> q;
	vector<int> result;
	for (int i = 1; i <= N; i++)
		q.push(i);

	while (q.size() > 0) {
		if (step++ % K == 0)
			result.push_back(q.front());
		else
			q.push(q.front());
		q.pop();
	}

	cout << "<";
	for (int i = 0; i < N - 1; i++)
		cout << result[i] << ", ";
	cout << result[N - 1] << ">";
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	Solve();
	return 0;
}