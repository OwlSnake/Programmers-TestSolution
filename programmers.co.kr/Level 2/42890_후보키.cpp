#include <string>
#include <vector>
#include <algorithm>

#include <iostream>

using namespace std;

int row, col;

int bitmask1Count(int bitmask) {
	int count = 0;
	while (bitmask > 0) {
		if (bitmask & 1) {
			count++;
		}
		bitmask >>= 1;
	}
	return count;
}

bool bitmaskAsc(int a, int b) {
	return bitmask1Count(a) < bitmask1Count(b);
}

bool isCK(const vector<vector<string>>& relation, int bitmask) {
	// �� row�� �����ϴ� ��� ����� ��
	for (int i = 0; i < row - 1; i++) {
		for(int j = i + 1; j < row; j++) {
			// ������ �� row ��
			bool unique = true;
			for (int k = 0; k < col; k++) {
				// bitmask�� ���Ե� column����
				if (bitmask & (1 << k)) {
					// �ϳ��� �ٸ��� false
					if (relation[i][k] != relation[j][k]) {
						unique = false;
						break;
					}
				}
			}
			if (unique) {
				// �ϳ��� �ٸ��� ���ϼ� ����
				return false;
			}

		}
	}
	return true;
}

int solution(vector<vector<string>> relation) {
	int answer = 0;
	row = relation.size();
	col = relation[0].size();
	vector<int> validMasks;

	int bitMaskMax = 1 << col;
	cout << col << "\n";
	for (int bitmask = 1; bitmask < bitMaskMax; bitmask++) {
		if (isCK(relation, bitmask)) {
			validMasks.push_back(bitmask);
		}
	}

	// ���� column ������ �� ����
	sort(validMasks.begin(), validMasks.end(), bitmaskAsc);
	
	// ���԰��� ����
	while (!validMasks.empty()) {
		int curMask = validMasks.front();
		validMasks.erase(validMasks.begin());
		answer++;

		for (auto iter = validMasks.begin(); iter != validMasks.end();) {
			if ((*iter & curMask) == curMask) {
				iter = validMasks.erase(iter);
			}
			else {
				iter++;
			}
		}
	}

	for (int n : validMasks) {
		cout << n << "\n";
	}

	return answer;
}

int main() {
	cout << solution({ {"100", "ryan", "music", "2"},{"200", "apeach", "math", "2"},{"300", "tube", "computer", "3"},{"400", "con", "computer", "4"},{"500", "muzi", "music", "3"},{"600", "apeach", "music", "2"} });
	return 0;
}