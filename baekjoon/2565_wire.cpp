#include <iostream>
#include <algorithm>
using namespace std;

struct ln { int start, end; } line[105];
int DP[105];

bool lineCompare(ln a, ln b) {
	return a.start < b.start;
}

int main() 
{
	ios::sync_with_stdio(0); cin.tie(0);
	int N, result = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) 
		cin >> line[i].start >> line[i].end;

	sort(line, line + N + 1, lineCompare);

	for (int i = 1; i <= N; i++){
		DP[i] = 1;
		for (int j = 1; j < i; j++) {
			if (line[i].end > line[j].end && DP[i] <= DP[j])
				DP[i] = DP[j] + 1;
		}
		result = max(result, DP[i]);
	}

	cout << N - result;

	return 0;
}
