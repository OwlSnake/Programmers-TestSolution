#include <string>
#include <vector>
#include <queue>

#include <iostream>
using namespace std;


int solution(vector<vector<int>> jobs) {

	int totalWaitTime = 0;
	int timer = 0;

	// std::greater을 사용해야 작은 값이 top에 온다
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

	sort(jobs.begin(), jobs.end());
	timer = jobs[0][0];
	
	int i = 0;
	while (!q.empty() || i < jobs.size()) {
		while (i < jobs.size() && jobs[i][0] <= timer) {
			// 소요시간을 기준으로 정렬
			q.push(make_pair(jobs[i][1], jobs[i][0]));
			i++;
		}

		if (!q.empty()) {
			timer += q.top().first;
			totalWaitTime += timer - q.top().second;
			q.pop();
		}
		else {
			timer = jobs[i][0];
		}
	}
	return totalWaitTime / jobs.size();
}

void main() {
	cout << solution({ {0,3}, {1,9}, {2,6} }) << endl;
}