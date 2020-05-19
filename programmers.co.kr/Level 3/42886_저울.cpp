#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> weight) {
	sort(weight.begin(), weight.end());

	int sum = 0;
	for (int i = 0; i < weight.size(); i++) {
		if (sum + 1 < weight[i])
			break;
		sum += weight[i];
	}
	return sum + 1;
}

void main() {
	cout << solution({ 3,1,6,2,7,30,1 }) << endl;
	cout << solution({ 1,1,1,1,1,6 }) << endl;
}