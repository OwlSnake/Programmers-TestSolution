#include <iostream>
#include <queue>
using namespace std;

const int MAX = 101;
enum { UP = 0, RIGHT = 1, DOWN = 2, LEFT = 3 };
enum { APPLE = 'a' , EMPTY = '.' };

int N, K, L;
char map[MAX][MAX] = { EMPTY };

// 뱀의 방향과 머리, 꼬리의 위치를 저장
struct Snake
{
	int dir = RIGHT;
	int hrow = 0, hcol = 0;
	int trow = 0, tcol = 0;
} s;

// L개의 방향 전환 정보를 저장
struct Move {
	int time;
	char rotDir;
};
queue<Move> moves;

int timer = 0;

void input() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			map[i][j] = EMPTY;
	
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		int row, col;
		cin >> row >> col;
		map[row - 1][col - 1] = APPLE;
	}

	cin >> L;
	for (int i = 0; i < L; i++)
	{
		Move mv;
		cin >> mv.time >> mv.rotDir;
		moves.push(mv);	
	}

	map[0][0] = s.dir;
}

// 디버그용 함수
void printMap() {
	cout << "TIME " << timer << '\n';
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] < 4 && map[i][j] >= 0)
				cout << (char)(map[i][j] + '0') << " ";
			else
				cout << map[i][j] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}

bool isInMap(int row, int col) {
	return row >= 0 && col >= 0 && row < N && col < N;
}

bool moveSnake() {
	int nrow = s.hrow, ncol = s.hcol;
	int dx = 0, dy = 0;

	// 방향에 따른 이동 후 머리 위치 계산
	switch (s.dir) {
	case UP:	nrow = s.hrow - 1;	ncol = s.hcol;	break;
	case DOWN:	nrow = s.hrow + 1;	ncol = s.hcol;	break;
	case LEFT:	nrow = s.hrow;	ncol = s.hcol - 1;	break; 
	case RIGHT:	nrow = s.hrow;	ncol = s.hcol + 1;	break;
	}

	// 충돌 시 종료
	if (!isInMap(nrow, ncol))
		return false;
	if (map[nrow][ncol] != EMPTY && map[nrow][ncol] != APPLE)
		return false;

	// 머리 이동
	s.hrow = nrow;
	s.hcol = ncol;

	// 사과를 먹지 않았으면 꼬리 제거
	// 이동 방향으로 뱀의 위치를 기록해 꼬리가 어디로 이동했는지 알 수 있다
	if (map[nrow][ncol] != APPLE) {
		int prevtrow = s.trow, prevtcol = s.tcol;

		switch (map[s.trow][s.tcol]) {
		case UP:	s.trow--;	break;
		case DOWN:	s.trow++;	break;
		case LEFT:	s.tcol--;	break;
		case RIGHT:	s.tcol++;	break;
		}

		map[prevtrow][prevtcol] = EMPTY;
	}

	// 이동 후 방향 전환
	if (!moves.empty() && timer == moves.front().time) {
		if (moves.front().rotDir == 'L') {
			s.dir--;
			if (s.dir < 0) s.dir = 3;
		}
		else {
			s.dir++;
			if (s.dir > 3) s.dir = 0;
		}
		moves.pop();
	}
	// 지도에 이동방향 표시
	map[s.hrow][s.hcol] = s.dir;

	return true;
}

void solve() {
	while (true) {
		timer++;

		// 충돌 시 종료
		if (!moveSnake())
			return;

		// 디버그용
		 printMap();
	}
}

int main() {
	input();
	solve();

	cout << timer;
	return 0;
}
