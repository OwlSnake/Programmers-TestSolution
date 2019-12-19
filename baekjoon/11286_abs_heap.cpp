#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

void Solve()
{
	int N, t;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> t;
		if (t == 0) {
			if (q.empty())
				cout << "0\n";
			else {
				cout << q.top().second << '\n';
				q.pop();
			}
		}
		else
			q.push(make_pair(abs(t), t));
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	Solve();
	return 0;
}