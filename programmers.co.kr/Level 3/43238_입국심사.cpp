#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

long long solution(int n, vector<int> times) {
	long long answer;

	long long minTime = 1000000000;
	for (long long time : times) {
		if (minTime > time)
			minTime = time;
	}

	long long end = minTime * n;
	long long begin = end / n;
	long long mid = 0;
	// Binary search
	while (begin <= end)
	{
		mid = (begin + end) / 2;
		printf("[%d, %d]\n", begin, end);
		
		long long cnt = 0;
		for (auto& time : times) {
			cnt += mid / time;
		}
		cout << "test " << mid << ": " << cnt << endl;

		if (cnt >= n) {
			end = mid - 1;
			answer = mid;
		}
		else {
			begin = mid + 1;
		}
	}

	return answer;
}

void main() {
	cout << solution(6, { 7, 10 }) << endl << endl; // 28
	cout << solution(20, { 1, 10 }) << endl; // 19
}