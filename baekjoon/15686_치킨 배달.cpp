#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct point {
	int row, col;
	point(int r, int c) {
		row = r, col = c;
	}
};

int N, M, map[51][51];
int answer = 9999999;

vector<point> houses, chickens;
int storeToClose = 0;
bool open[13];

void input() {
	cin >> N >> M;
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < N; c++)
		{
			cin >> map[r][c];
			if (map[r][c] == 1)
				houses.push_back(point(r, c));
			else if (map[r][c] == 2)
			{
				open[chickens.size()] = true;
				chickens.push_back(point(r, c));
			}
		}
	}
	storeToClose = chickens.size() - M;
}

int calcDist() {
	int distSum = 0;
	for (point h : houses) {
		int minDist = 10000;
		for (int i = 0; i < chickens.size(); i++) {
			if (!open[i])
				continue;

			int dist = abs(h.row - chickens[i].row) + abs(h.col - chickens[i].col);
			minDist = min(minDist, dist);
		}
		distSum += minDist;
	}
	return distSum;
}


void dfs(int depth, int lastClosed) {
	if (depth >= storeToClose)
	{
		answer = min(answer, calcDist());
		return;
	}
	
	for (int i = lastClosed; i < chickens.size(); i++)
	{
		if (!open[i])
			continue;

		open[i] = false;
		dfs(depth + 1, i);
		open[i] = true;
	}
	return;
}

void solve() {
	dfs(0, 0);
}

int main() {
	input();
	solve();
	cout << answer;
	return 0;
}
