#include <string>
#include <vector>

using namespace std;

vector<int> s;
int answer = 0;

int solution(vector<vector<int>> board, vector<int> moves) {
	for (int move : moves) {
		for (int i = board.size() - 1; i >= 0; i--) {
			if (board[i][move] != 0) {
				if (!s.empty()) {
					if (s.back() == board[i][move]) {
						answer++;
						s.pop_back();
					}
					else {
						s.push_back(board[i][move]);
					}
				}
				board[i][move] = 0;
			}
		}
	}

	return answer;
}