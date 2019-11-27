#include <iostream>
using namespace std;

char arr[64][64];
string code;

void CheckColor(int row, int col, int size) {
	// Check if color of this part is identical
	bool isColorSame = true;
	for (int i = row; i < row + size; i++)
	{
		for (int j = col; j < col + size; j++) {
			if (arr[row][col] != arr[i][j]) {
				isColorSame = false;
				break;
			}
		}
		if (!isColorSame)
			break;
	}
	// If same, add to code
	if (isColorSame) {
		if (arr[row][col] == '0')
			code += "0";
		else
			code += "1";
		return;
	}
	// If not same, divide and check
	code += "(";
	CheckColor(row, col, size / 2);
	CheckColor(row, col + size / 2, size / 2);
	CheckColor(row + size / 2, col, size / 2);
	CheckColor(row + size / 2, col + size / 2, size / 2);
	code += ")";
}

void Solve()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string row;
		cin >> row;
		for (int j = 0; j < N; j++)
			arr[i][j] = row[j];
	}

	CheckColor(0, 0, N);
	cout << code;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	Solve();
	return 0;
}