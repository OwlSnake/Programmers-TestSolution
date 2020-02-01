#include <iostream>
#include <algorithm> // std::max
#include <queue>
#include <cstring> // std::memcpy
using namespace std;

const int MAX = 20;
enum DIR { UP = 0, DOWN = 1, LEFT = 2, RIGHT = 3 };

int N, map[MAX][MAX];
int answer = 0;

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
}
int getMaximumBlock() {
	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			result = max(result, map[i][j]);
		}
	}
	return result;
}

void move(int dir) {
	// map 배열의 블록들을 방향에 따라 이동
	switch (dir) {
	case UP:
		for (int col = 0; col < N; col++)
		{
			// 0을 제외한 블록들을 Queue에 넣고 map은 0으로 비움
			queue<int> q;
			for (int row = 0; row < N; row++) {
				if (map[row][col] != 0)
					q.push(map[row][col]);
				map[row][col] = 0;
			}

			if (q.empty())
				continue;

			// 하나씩 꺼내면서 합칠 수 있는 지 확인
			map[0][col] = q.front();
			q.pop();
			bool merged = false;
			int idx = 1;
			while (!q.empty()) {
				if (!merged && map[idx - 1][col] == q.front()) {
					map[idx - 1][col] *= 2;
					merged = true;
				}
				else {
					map[idx][col] = q.front();
					idx++;
					merged = false;
				}
				q.pop();
			}
		}
		break;

	case DOWN:
		for (int col = 0; col < N; col++)
		{
			queue<int> q;

			for (int row = N-1; row >= 0; row--)
				if (map[row][col] != 0)
					q.push(map[row][col]);

			if (q.empty())
				continue;

			map[N - 1][col] = q.front();
			bool merged = false;
			int idx = N - 2;
			q.pop();
			while (!q.empty()) {
				if (!merged && map[idx + 1][col] == q.front()) {
					map[idx + 1][col] *= 2;
					q.pop();
					merged = true;
				}
				else {
					map[idx][col] = q.front();
					idx--;
					q.pop();
					merged = false;
				}
			}
			while (idx >= 0) {
				map[idx][col] = 0;
				idx--;
			}
		}
		break;

	case LEFT:
		for (int row = 0; row < N; row++)
		{
			queue<int> q;

			for (int col = 0; col < N; col++)
				if (map[row][col] != 0)
					q.push(map[row][col]);

			if (q.empty())
				continue;

			map[row][0] = q.front();
			bool merged = false;
			int idx = 1;
			q.pop();
			while (!q.empty()) {
				if (!merged && map[row][idx - 1] == q.front()) {
					map[row][idx - 1] *= 2;
					q.pop();
					merged = true;
				}
				else {
					map[row][idx] = q.front();
					idx++;
					q.pop();
					merged = false;
				}
			}
			while (idx < N) {
				map[row][idx] = 0;
				idx++;
			}
		}
		break;

	case RIGHT:
		for (int row = 0; row < N; row++)
		{
			queue<int> q;

			for (int col = N-1; col >= 0; col--)
				if (map[row][col] != 0)
					q.push(map[row][col]);

			if (q.empty())
				continue;

			map[row][N - 1] = q.front();
			q.pop();
			bool merged = false;
			int idx = N - 2;

			while (!q.empty()) {
				if (!merged && map[row][idx + 1] == q.front()) {
					map[row][idx + 1] *= 2;
					q.pop();
					merged = true;
				}
				else {
					map[row][idx] = q.front();
					idx--;
					q.pop();
					merged = false;
				}
			}

			while (idx >= 0) {
				map[row][idx] = 0;
				idx--;
			}
		}
		break;
	}
}

void dfs(int depth){
	// 최대 깊이에 도달했을 때 블럭의 최대를 구한 뒤 DFS 종료
	if (depth >= 5) {
		answer = max(answer, getMaximumBlock());
		return;
	}

	// 이동 전 현재 깊이의 map 저장
	int prevMap[MAX][MAX];
	memcpy(prevMap, map, sizeof(map));

	// 4방향 이동에 대해 탐색
	for (int i = 0; i < 4; i++)
	{
		move(i);
		dfs(depth + 1);
		// map 복구
		memcpy(map, prevMap, sizeof(map));
	}
}

int main() {
	input();
	dfs(0);
	cout << answer;
	return 0;
}
