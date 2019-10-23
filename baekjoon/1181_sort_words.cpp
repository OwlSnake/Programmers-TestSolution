#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string arr[20001];

bool WordCompare(const string& s1, const string& s2) {
	if (s1.size() != s2.size())
		return s1.size() < s2.size();
	else
		return s1.compare(s2) < 0;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N, WordCompare);

	cout << arr[0] << '\n';
	for (int i = 1; i < N; i++) {
		if (arr[i - 1] == arr[i])
			continue;
		cout << arr[i] << '\n';
	}

	return 0;
}
