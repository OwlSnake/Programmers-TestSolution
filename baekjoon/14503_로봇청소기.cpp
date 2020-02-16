#include <iostream>
using namespace std;

int map[50][50];
int N, M;
int r, c, d;
int answer = 0;

enum DIR { UP = 0, RIGHT = 1, DOWN = 2, LEFT = 3 };
enum MAP { WALL = 1, EMPTY = 0, CLEANED = 2 };
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };


void input() {
	cin >> N >> M;
	cin >> r >> c >> d;
	for (int row = 0; row < N; row++)
		for (int col = 0; col < M; col++)
			cin >> map[row][col];
}

void solve() {
	while (true) {
		// 현위치 청소
		if (map[r][c] != CLEANED) {
			map[r][c] = CLEANED;
			answer++;
		}

		// cout << "Cleaned " << r << ", " << c << " Dir: " << d << " \n";

		// 네 방향 확인
		int nd = d;
		bool moved = false;
		for (int i = 0; i < 4; i++)
		{
			nd = (d + 3) % 4;
			if (map[r + dy[nd]][c + dx[nd]] == EMPTY) {
				// a
				d = nd;
				r = r + dy[nd];
				c = c + dx[nd];
				moved = true;
				break;
			}
			else {
				// b
				d = nd;
				continue;
			}
		}
		// a 경우 1부터 진행
		if (moved)
			continue;

		// d 뒤 확인
		nd = (d + 2) % 4;
		if (map[r + dy[nd]][c + dx[nd]] == WALL) {
			// 작동 중지
			break;
		}
		// c 후진 가능
		r = r + dy[nd];
		c = c + dx[nd];
	}
	
}

int main() {
	input();
	solve();

	cout << answer;
	return 0;
}
