#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, K;
	vector<int> list, answer;
	cin >> N >> K;

	for (int i = 0; i < N; i++)
		list.push_back(i + 1);

	int curPos = -1;
	while (list.size() > 0) {
		curPos += K;
		curPos %= list.size();

		answer.push_back(list[curPos]);
		list.erase(list.begin() + curPos);
		curPos -= 1;
	}

	cout << '<';
	for (int i = 0; i < answer.size() - 1; i++)
		cout << answer[i] << ", ";
	cout << answer[answer.size() - 1] << '>';

	return 0;
}

