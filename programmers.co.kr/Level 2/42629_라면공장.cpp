#include <string>
#include <vector>
#include <queue>

#include <iostream>
using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	int answer = 0;
	int curDates = 0;
	int idx = 0;

	priority_queue<int> supplyQ;

	while (curDates < k)
	{
		cout << curDates << " date / stock " << stock << "\n";
		if (idx < dates.size() && curDates == dates[idx]) {
			supplyQ.push(supplies[idx]);
			idx++;
		}

		if (stock == 0) {
			stock += supplyQ.top();
			supplyQ.pop();
			answer++;
		}

		stock--;
		curDates++;
	}

	return answer;
}

int main() {
	solution(4, { 4,10,15 }, { 20,5,10 }, 30);
	return 0;

}