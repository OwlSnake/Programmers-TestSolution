#include <iostream>
using namespace std;

int arr[2200][2200];
int numCount[3];
string code;


void CheckPart(int row, int col, int size) {
	// Check if number of this part is identical
	bool isNumSame = true;
	for (int i = row; i < row + size; i++)
	{
		for (int j = col; j < col + size; j++) {
			if (arr[row][col] != arr[i][j]) {
				isNumSame = false;
				break;
			}
		}
		if (!isNumSame)
			break;
	}
	// If same, increase count
	if (isNumSame) {
		if (arr[row][col] == -1)
			numCount[0]++;
		else if (arr[row][col] == 0)
			numCount[1]++;
		else
			numCount[2]++;
		
		return;
	}
	// If not same, divide and check
	int pSize = size / 3;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			CheckPart(row + pSize * i, col + pSize * j, pSize);
}

void Solve()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];

	CheckPart(0, 0, N);
	
	for (int i = 0; i < 3; i++)
		cout << numCount[i] << '\n';
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	Solve();
	return 0;
}