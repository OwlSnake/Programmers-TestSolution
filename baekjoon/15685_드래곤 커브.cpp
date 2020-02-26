#include <iostream>
#include <vector>
using namespace std;

int N, map[101][101];
vector<int> curve[11];
enum { R = 0, U = 1, L = 2, D = 3 };

void calcCurves() {
	curve[0].push_back(0);
	for (int i = 1; i <= 10; i++)
	{
		curve[i] = curve[i - 1];
		for (int j = curve[i-1].size() - 1; j >= 0; j--)
			curve[i].push_back((curve[i - 1][j] + 1) % 4);
	}
}

void drawCurves(int x, int y, int dir, int gen) {
	int curX = x, curY = y;
	map[y][x] = 1;

	// È¸Àü
	vector<int> newDir;
	for (int i = 0; i < curve[gen].size(); i++)
	{
		newDir.push_back((curve[gen][i] + dir) % 4);
	}

	for (int i = 0; i < newDir.size(); i++)
	{
		switch (newDir[i]) {
		case R:	curX++; break;
		case U:	curY--; break;
		case L:	curX--; break;
		case D:	curY++; break;
		}
		map[curY][curX] = 1;
	}
}

int squareCount() {
	int count = 0;
	for (int r = 0; r < 100; r++)
	{
		for (int c = 0; c < 100; c++) 
		{
			if (map[r][c] && map[r][c + 1] && map[r + 1][c] && map[r + 1][c + 1])
				count++;
		}
	}
	return count;
}

void solve() {
	cin >> N;
	
	calcCurves();

	for (int i = 0; i < N; i++)
	{
		int x, y, dir, gen;
		cin >> x >> y >> dir >> gen;
		drawCurves(x, y, dir, gen);
	}

	cout << squareCount();
}

int main() {
	solve();
	return 0;
}