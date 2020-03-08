#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int maxScore = 0;
int map[500][500];
bool visited[500][500] = { 0 };
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

struct point {
	int r, c; 
	point(int row, int col) : r(row), c(col) {};
};

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
}

bool isInMap(point p) { return p.r >= 0 && p.r < N && p.c >= 0 && p.c < M; }

void dfs(point p, int depth, int score) {
	if (depth >= 4) {
		maxScore = max(maxScore, score);
		return;
	}

	for (int dir = 0; dir < 4; dir++)
	{
		point newP = point(p.r + dy[dir], p.c + dx[dir]);
		if (!isInMap(newP)) continue;
		if (visited[newP.r][newP.c]) continue;

		visited[newP.r][newP.c] = true;
		dfs(newP, depth + 1, score + map[newP.r][newP.c]);
		visited[newP.r][newP.c] = false;
	}
}

void calcTBlockScore(point p) {
	vector<point> validP;
	validP.push_back(p);
	int score = map[p.r][p.c];
	int minNearBlock = 1000;

	for (int dir = 0; dir < 4; dir++)
	{
		point newP = point(p.r + dy[dir], p.c + dx[dir]);
		if (!isInMap(newP))
			continue;

		validP.push_back(newP);
		score += map[newP.r][newP.c];
		minNearBlock = min(minNearBlock, map[newP.r][newP.c]);
	}

	// T블럭이 만들어지는 경우
	if (validP.size() == 4) {
		maxScore = max(maxScore, score);
	}
	// 십자가 만들어지는 경우
	else if (validP.size() == 5) {
		maxScore = max(maxScore, score - minNearBlock);
	}
	return;
}

void solve() {
	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < M; col++)
		{
			// 테트로미노 계산(DFS)
			vector<point> pList;
			visited[row][col] = true;
			dfs(point(row, col), 1, map[row][col]);
			visited[row][col] = false;

			// T 블럭 계산
			calcTBlockScore(point(row, col));
		}
	}
}

int main() {
	input();
	solve();
	cout << maxScore;
	return 0;
}
