#include <iostream>
#include <queue>
using namespace std;

int N, L, map[100][100] = { 0 };
int answer = 0;

void input() {
	cin >> N >> L;
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			cin >> map[row][col];
		}
	}
}

void solve() {
	
	for (int row = 0; row < N; row++)
	{
		bool validPath = true;
		int flatDist = 1;
		// 높이 같음
		for (int i = 1; i < N; i++) {
			if (map[row][i] == map[row][i - 1]) {
				flatDist++;
			}
			// 한칸 높아짐
			else if (map[row][i] == map[row][i - 1] + 1) {
				if (flatDist < L) {
					validPath = false;
					break;
				}

				flatDist = 1;
			}
			// 한칸 낮아짐
			else if (map[row][i] == map[row][i - 1] - 1) {
				int nextFlatDist = 0;
				for (int j = i; j < i + L && j < N; j++)
				{
					if (map[row][i] == map[row][j])
						nextFlatDist++;
					else
						break;
				}
				if (nextFlatDist < L) {
					validPath = false;
					break;
				}
				i = i + L - 1;
				flatDist = 0;
			}
			// 높이 차이 2 이상
			else {
				validPath = false;
				break;
			}
		}

		if (validPath)
			answer++;
	}
}

void flip() {
	for (int row = 0; row < N; row++)
	{
		for (int col = row + 1; col < N; col++) {
			int temp = map[row][col];
			map[row][col] = map[col][row];
			map[col][row] = temp;
		}
	}
}

int main() {
	input();

	solve();
	flip();
	solve();

	cout << answer;
	return 0;
}
