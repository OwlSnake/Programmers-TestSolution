#include <iostream>
using namespace std;

int N, answer = 0;
int queen[16];

bool IsQueenSafe(int row) {
	for (int i = 1; i < row; i++) {
		if (queen[i] == queen[row])
			return false;
		if (abs(queen[i] - queen[row]) == abs(i - row))
			return false;
	}	
	return true;
}

void BackTrack(int row) {
	if (row == N + 1)
		answer++;
	else {
		for (int i = 1; i <= N; i++)
		{
			queen[row] = i;
			if (IsQueenSafe(row))
				BackTrack(row + 1);
		}
	}

}

int main() 
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;

	BackTrack(1);
	cout << answer;
	return 0;
}
