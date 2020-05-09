#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> budgets, int M) {

	sort(budgets.begin(), budgets.end());

	int leftCount = budgets.size();
	// 모든 요청에 배정 가능한 경우 가장 큰 지역으로
	int limit = budgets.back();
	for (int i = 0; i < budgets.size(); i++)
	{
		M -= budgets[i];
		leftCount--;

		// 배정 불가능한 경우
		if (budgets[i] * leftCount > M) {
			leftCount++;
			M += budgets[i];
			limit = M / leftCount;

			break;
		}
	}
	return limit;
}