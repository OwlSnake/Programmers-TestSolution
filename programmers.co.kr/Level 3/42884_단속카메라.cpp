#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool compareExit(vector<int>& a, vector<int>& b) { return a[1] < b[1]; }

int solution(vector<vector<int>> routes) {
	int camCount = 0;

	sort(routes.begin(), routes.end(), compareExit);

	while (!routes.empty()) {
		int firstExit = routes[0][1];
		for (int i = 0; i < routes.size(); i++) {
			if (routes[i][0] <= firstExit) {
				routes.erase(routes.begin() + i);
				i--;
			}
		}
		camCount++;
	}
	return camCount;
}

void main() {
	cout << solution({ { -20,15 }, { -14,5 }, { -18,-13 }, { -5,-3 } }) << endl;
	cout << solution({ { 0,0 }, { 0,0 }, {0, 1} }) << endl;
}