#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M;
int map[8][8], tempMap[8][8];
int maxSafeAreaCount = 0;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

enum { SAFE = 0, WALL = 1, VIRUS = 2 };

struct point {
	int row, col;
};
point wall[3];

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
}

bool isInMap(int r, int c) {
	return r >= 0 && r < N && c >= 0 && c < M;
}

int getSafeAreaCount() {
	int count = 0;
	for (int r = 0; r < N; r++)
		for (int c = 0; c < M; c++)
			if (tempMap[r][c] == SAFE)
				count++;
	return count;
}

void spreadVirus() {
	int prevCount = 0;
	int count = getSafeAreaCount();
	// tempMap에서 바이러스 확산 테스트
	while (prevCount != count)
	{
		prevCount = count;
		for (int r = 0; r < N; r++)
		{
			for (int c = 0; c < M; c++)
			{
				if (tempMap[r][c] == VIRUS)
				{
					for (int i = 0; i < 4; i++)
					{
						int newr = r + dy[i];
						int newc = c + dx[i];
						if (isInMap(newr, newc) && tempMap[newr][newc] == SAFE)
							tempMap[newr][newc] = VIRUS;
					}
				}
			}
		}
		count = getSafeAreaCount();
	}
}

void solve() {
	// 벽을 세울 수 있는 모든 경우 확인
	for (int r0 = 0; r0 < N; r0++)
	{
		for (int c0 = 0; c0 < M; c0++)
		{
			if (map[r0][c0] != SAFE)	continue;

			wall[0].row = r0;
			wall[0].col = c0;
			
			for (int r1 = r0; r1 < N; r1++)
			{
				for (int c1 = 0; c1 < M; c1++)
				{
					if (map[r1][c1] != SAFE)	continue;
					if (r1 == r0 && c1 == c0)	continue;

					wall[1].row = r1;
					wall[1].col = c1;

					for (int r2 = r1; r2 < N; r2++)
					{
						for (int c2 = 0; c2 < M; c2++)
						{
							if (map[r2][c2] != SAFE)	continue;
							if (r2 == r1 && c2 == c1)	continue;
							if (r2 == r0 && c2 == c0)	continue;

							wall[2].row = r2;
							wall[2].col = c2;

							// 벽을 세운 뒤 안전 영역 크기 확인
							memcpy(tempMap, map, sizeof(map));
							for (int i = 0; i < 3; i++)
								tempMap[wall[i].row][wall[i].col] = WALL;

							spreadVirus();

							maxSafeAreaCount = max(maxSafeAreaCount, getSafeAreaCount());
						}
					}
				}
			}
		}
	}
}
	

int main() {
	input();
	solve();
	cout << maxSafeAreaCount;
	return 0;
}
