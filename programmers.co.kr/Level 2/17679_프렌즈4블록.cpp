#include <string>
#include <vector>
#include <queue>

#include <iostream>	

using namespace std;

int removeBlocks(int m, int n, vector<string>& board) {
	int removeCount = 0;
	vector<vector<int>> removeBlock(m, vector<int>(n));

	for (int r = 0; r < m - 1; r++) {
		for (int c = 0; c < n - 1; c++)
		{
			if (board[r][c] == board[r + 1][c] 
				&& board[r][c] == board[r][c + 1] 
				&& board[r + 1][c] == board[r + 1][c + 1]
				&& board[r][c] != ' ') {

				removeBlock[r][c] = 1;
				removeBlock[r][c+1] = 1;
				removeBlock[r+1][c] = 1;
				removeBlock[r+1][c+1] = 1;
			}
		}
	}

	for (int r = 0; r < m; r++) {
		for (int c = 0; c < n; c++){
			if (removeBlock[r][c]) {
				removeCount++;
				board[r][c] = ' ';
			}
		}
	}

	// 떨어뜨리기
	for (int c = 0; c < n; c++) {
		queue<int> newCol;
		for (int r = m - 1; r >= 0; r--) {
			if (board[r][c] != ' ') {
				newCol.push(board[r][c]);
				board[r][c] = ' ';
			}
		}

		for (int r = m - 1; !newCol.empty(); r--) {
			board[r][c] = newCol.front();
			newCol.pop();
		}
	}

	return removeCount;
}

int solution(int m, int n, vector<string> board) {
	int answer = 0;

	while(true) {
		int removeCount = removeBlocks(m, n, board);
		answer += removeCount;
		if (removeCount == 0)
			break;
	}

	cout << "answer: " << answer << "\n";
	return answer;
}

void main() {
	solution(6, 2, { "DD", "CC", "AA", "AA", "CC", "DD" });
}