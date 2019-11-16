#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, t, answer = 0;
vector<int> ropeStr;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> t;
		ropeStr.push_back(t);
	}

	sort(ropeStr.begin(), ropeStr.end(), greater<int>());

	for (int i = 0; i < N; i++)
	{
		int maxWeight = (i + 1) * ropeStr[i];
		answer = (maxWeight > answer) ? maxWeight : answer;
	}
	
	cout << answer;
	return 0;
}