#include <iostream>
using namespace std;

int arr[128][128];
int wCount = 0, bCount = 0;

void CheckColor(int row, int col, int size) {
	// Check if color of this paper is identical
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
	// If same, update count
	if (isColorSame) {
		if (arr[row][col] == 0)
			wCount++;
		else
			bCount++;
		return;
	}
	// If not same, divide paper and check
	CheckColor(row, col, size / 2);
	CheckColor(row + size / 2, col, size / 2);
	CheckColor(row, col + size / 2, size / 2);
	CheckColor(row + size / 2, col + size / 2, size / 2);
}

void Solve()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];

	CheckColor(0, 0, N);

	cout << wCount << '\n' << bCount;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	Solve();
	return 0;
}