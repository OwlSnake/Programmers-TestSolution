#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> results) {
	set<int> win[101], lose[101];

	for (auto& result : results) {
		win[result[1]].insert(result[0]);
		lose[result[0]].insert(result[1]);
	}

	// �� ���� i�� ����
	for (int i = 1; i <= n; i++) {
		// i���� �� ���� l��
		for (auto& l : lose[i]) {
			// i�� �̱� ���� w���� ����
			for (auto& w : win[i]) {
				win[l].insert(w);
				lose[w].insert(l);
			}
		}
	}

	int answer = 0;
	for (int i = 1; i <= n; i++) {
		if ((win[i].size() + lose[i].size()) == (n - 1)) {
			answer++;
		}
		cout << win[i].size() << ", " << lose[i].size() << endl;
	}
	return answer;
}

void main() {
	cout << solution(5, { { 4,3 }, {4,2}, {3,2}, {1,2}, {2,5} }) << endl;
}