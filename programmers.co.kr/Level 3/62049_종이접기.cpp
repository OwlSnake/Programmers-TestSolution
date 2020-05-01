#include <string>
#include <vector>

#include <iostream>

using namespace std;

vector<int> solution(int n) {
	vector<int> result[21];
	result[1] = { 0 };

	for (int i = 2; i <= n; i++)
	{
		int curveCount = 0;
		for (int j = 0; j < result[i-1].size(); j++)
		{
			result[i].push_back(curveCount % 2);
			curveCount++;
			result[i].push_back(result[i - 1][j]);
		}
		result[i].push_back(curveCount % 2);
	}

	for (int c : result[n]) {
		cout << c << ", ";
	}
	cout << endl;

	return result[n];
}

void main() {
	solution(1);
	solution(2);
	solution(3);
	solution(4);
}