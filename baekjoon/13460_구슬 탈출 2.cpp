#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

enum DIR
{
	UP = 0, DOWN = 1, LEFT = 2, RIGHT = 3
};

struct point { int rx, ry, bx, by, cnt; };
int N, M, answer = -1;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int rx, ry, bx, by;
int hx, hy;

queue<point> q;

const int MAX = 11;
bool visit[MAX][MAX][MAX][MAX] = { false };

char map[MAX][MAX];


void input()
{
	// 입력
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> map[i];
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 'R') {
				rx = i;
				ry = j;
				map[i][j] = '.';
			}
			else if (map[i][j] == 'B') {
				bx = i;
				by = j;
				map[i][j] = '.';
			}
		}
		
	}

}

void bfs()
{

	while (!q.empty())
	{
		// 탐색 완료 확인
		point startp = q.front();
		q.pop();

		if (map[startp.rx][startp.ry] == 'O') {
			answer = startp.cnt;
			return;
		}


		if (startp.cnt > 10) {
			answer = -1;
			return;
		}

		// 네 가지 방향 테스트, 가능한 경우 q에 추가
		for (int i = 0; i < 4; i++) {
			point newp = startp;
			newp.cnt++;

			// R 이동
			while (true) {
				newp.rx += dx[i];
				newp.ry += dy[i];
				if (map[newp.rx][newp.ry] == 'O')
					break;
				else if (map[newp.rx][newp.ry] == '#') {
					newp.rx -= dx[i];
					newp.ry -= dy[i];
					break;
				}
			}
			
			// B 이동
			bool failed = false;
			while (true) {
				newp.bx += dx[i];
				newp.by += dy[i];
				if (map[newp.bx][newp.by] == 'O') {
					failed = true;
					break;
				}
				else if (map[newp.bx][newp.by] == '#') {
					newp.bx -= dx[i];
					newp.by -= dy[i];
					break;
				}
			}
			if (failed)
				continue;

			// R과 B가 겹칠 경우 이동거리 비교 후 위치 수정
			if (newp.rx == newp.bx && newp.ry == newp.by) {
				int rdist = abs(startp.rx - newp.rx) + abs(startp.ry - newp.ry);
				int bdist = abs(startp.bx - newp.bx) + abs(startp.by - newp.by);
				if (rdist < bdist) {
					newp.bx -= dx[i];
					newp.by -= dy[i];
				}
				else {
					newp.rx -= dx[i];
					newp.ry -= dy[i];
				}
			}

			// 중복되는 경우 제외
			if (visit[newp.rx][newp.ry][newp.bx][newp.by])
				continue;
			visit[newp.rx][newp.ry][newp.bx][newp.by] = true;

			// q에 추가
			q.push(newp);
		}
	}

	answer = -1;
	return;
}

int main() {
	input();
	q.push({ rx, ry, bx, by, 0 });
	visit[rx][ry][bx][by] = true;

	bfs();
	cout << answer;
	return 0;
}