#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> point;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		point.push_back(make_pair(y, x));
	}

	sort(point.begin(), point.end());
	for (int i = 0; i < N; i++)
		cout << point[i].second << ' ' << point[i].first << '\n';

	return 0;
}
