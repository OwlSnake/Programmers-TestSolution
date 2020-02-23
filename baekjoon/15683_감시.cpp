#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

struct cam {
	int type, row, col;
	cam(int t, int r, int c) { type = t, row = r, col = c; }
};
vector<cam> cams;
int N, M, map[8][8];
int minBlindCount = 64;

enum {BLIND = 0, WALL = 6};
enum {UP = 0, RIGHT = 1, DOWN = 2, LEFT = 3};

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] != BLIND && map[i][j] != WALL) {
				cams.push_back(cam(map[i][j], i, j));
				map[i][j] = BLIND;
			}
		}
	}
}

int countBlindSpots() {
	int count = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (map[i][j] == BLIND )
				count++;
	return count;
}

void drawLine(cam c, int dir) {
	switch (dir) {
	case UP:
		for (int i = c.row; i >= 0; i--) {
			if (map[i][c.col] == BLIND)
				map[i][c.col] = '#';
			if (map[i][c.col] == WALL)
				break;
		}
		break;
	case RIGHT:
		for (int i = c.col; i < M; i++) {
			if (map[c.row][i] == BLIND)
				map[c.row][i] = '#';
			if (map[c.row][i] == WALL)
				break;
		}
	break;
	case DOWN:
		for (int i = c.row ; i < N; i++) {
			if (map[i][c.col] == BLIND)
				map[i][c.col] = '#';
			if (map[i][c.col] == WALL)
				break;
		}
	break;
	case LEFT:
		for (int i = c.col; i >= 0; i--) {
			if (map[c.row][i] == BLIND)
				map[c.row][i] = '#';
			if (map[c.row][i] == WALL)
				break;
		}
	break;
	}
}

// 카메라 타입에 따른 방향 계산
void useCam(cam c, int dir) {
	switch (c.type)
	{
	case 1:
		drawLine(c, dir);
		break;
	case 2:
		drawLine(c, dir);
		drawLine(c, (dir + 2) % 4);
		break;
	case 3:
		drawLine(c, dir);
		drawLine(c, (dir + 1) % 4);
		break;
	case 4:
		drawLine(c, dir);
		drawLine(c, (dir + 1) % 4);
		drawLine(c, (dir + 3) % 4);
		break;
	case 5:
		drawLine(c, UP);
		drawLine(c, RIGHT);
		drawLine(c, DOWN);
		drawLine(c, LEFT);
	default:
		break;
	}
}

void DFS(int depth) {
	// 탐색 깊이는 카메라 갯수
	if (depth >= cams.size()) {
		minBlindCount = min(minBlindCount, countBlindSpots());
		return;
	}

	int prevMap[8][8];

	cam c = cams[depth];
	// 2번, 5번 카메라는 네 방향을 모두 확인할 필요가 없음
	if (c.type == 2) {
		for (int dir = 0; dir < 2; dir++)
		{
			memcpy(prevMap, map, sizeof(map));
			useCam(c, dir);
			DFS(depth + 1);
			memcpy(map, prevMap, sizeof(map));
		}
	}
	else if (c.type == 5) {
		memcpy(prevMap, map, sizeof(map));
		useCam(c, UP);
		DFS(depth + 1);
		memcpy(map, prevMap, sizeof(map));
	}
	else {
		for (int dir = 0; dir < 4; dir++)
		{
			memcpy(prevMap, map, sizeof(map));
			useCam(c, dir);
			DFS(depth + 1);
			memcpy(map, prevMap, sizeof(map));
		}
	}

}

void solve() {
	DFS(0);
}
	

int main() {
	input();
	solve();
	cout << minBlindCount;
	return 0;
}
