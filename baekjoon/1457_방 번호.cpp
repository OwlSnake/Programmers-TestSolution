#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string roomNum;
	vector<int> cnt(10);
	cin >> roomNum;
	
	for (char c : roomNum)
		cnt[c - '0']++;

	int t = cnt[6] + cnt[9];
	cnt[6] = t / 2 + (t % 2);
	cnt[9] = t / 2;

	cout << *max_element(cnt.begin(), cnt.end());
	
	return 0;
}