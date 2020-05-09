#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> budgets, int M) {

	sort(budgets.begin(), budgets.end());

	int leftCount = budgets.size();
	// ��� ��û�� ���� ������ ��� ���� ū ��������
	int limit = budgets.back();
	for (int i = 0; i < budgets.size(); i++)
	{
		M -= budgets[i];
		leftCount--;

		// ���� �Ұ����� ���
		if (budgets[i] * leftCount > M) {
			leftCount++;
			M += budgets[i];
			limit = M / leftCount;

			break;
		}
	}
	return limit;
}