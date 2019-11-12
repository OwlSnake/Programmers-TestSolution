#include <iostream>
using namespace std;

int board[9][9];

bool IsNumValid(int num, int row, int col) {
	for (int i = 0; i < 9; i++)
		if (board[row][i] == num || board[i][col] == num)
			return false;

	for (int i = (row / 3)*3; i < (row / 3)*3 + 3; i++)
		for (int j = (col / 3)*3; j < (col / 3)*3 + 3; j++)
			if (num == board[i][j])
				return false;
		
	return true;
}

bool BackTrack(int row) {
	for (int i = row; i < 9; i++) {
		for (int j = 0; j < 9; j++) {

			if (board[i][j] == 0) {
				for (int num = 1; num <= 9; num++){
					if (IsNumValid(num, i, j)) {
						board[i][j] = num;
						if (BackTrack(i))
							return true;
						
						board[i][j] = 0;
					}
				}
				return false;
			}
		}
	}
	return true;
}

int main() 
{
	ios::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			cin >> board[i][j];

	BackTrack(0);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			cout << board[i][j] << ' ';
		cout << '\n';
	}

	return 0;
}
