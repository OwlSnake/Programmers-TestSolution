#include <string>
#include <unordered_set>
#include <iostream>

using namespace std;

unordered_set<int> nums[9];

int solution(int N, int number) {

	int base = 1;
	for (int i = 1; i <= 8; i++) {
		nums[i].insert(base * N);
		base = base * 10 + 1;
	}

	for (int i = 2; i <= 8; i++) {
		for (int j = 1; j < i; j++) {
			for (auto n1 : nums[j]) {
				for (auto n2 : nums[i - j]) {
					nums[i].insert(n1 + n2);
					nums[i].insert(n1 - n2);
					nums[i].insert(n1 * n2);

					if(n2 != 0)
						nums[i].insert(n1 / n2);
				}
			}
		}

		if (nums[i].count(number) > 0) {
			return i;
		}
	}
	return -1;
}

int main() {
	cout << solution(5, 12) << '\n';
	cout << solution(2, 11) << '\n';
	cout << solution(5, 31168) << '\n';
	return 0;
}
