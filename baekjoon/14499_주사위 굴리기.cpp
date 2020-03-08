#include <iostream>
#include <vector>
using namespace std;

const int MAX = 20;
int map[MAX][MAX] = { 0 };
int moves[1000];
int N, M, row, col, K;

enum { EAST = 1, WEST = 2, NORTH = 3, SOUTH = 4 };

struct Dice {
	int top = 0, bot = 0;
	int L = 0, R = 0, U = 0, D = 0;
} dice;

void input() {
	cin >> N >> M >> row >> col >> K;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < K; i++)
	{
		cin >> moves[i];
	}
}

bool insideMap(int r, int c) {
	return r >= 0 && r < N && c >= 0 && c < M;
}

void rollDice(int dir) {
	int t;
	switch (dir) {
	case EAST:
		t = dice.R;
		dice.R = dice.top;
		dice.top = dice.L;
		dice.L = dice.bot;
		dice.bot = t;
		break;
	case WEST:
		t = dice.L;
		dice.L = dice.top;
		dice.top = dice.R;
		dice.R = dice.bot;
		dice.bot = t;
		break;
	case NORTH:
		t = dice.U;
		dice.U = dice.top;
		dice.top = dice.D;
		dice.D = dice.bot;
		dice.bot = t;
		break;
	case SOUTH:
		t = dice.D;
		dice.D = dice.top;
		dice.top = dice.U;
		dice.U = dice.bot;
		dice.bot = t;
		break;
	}
}

void solve() {
	for (int i = 0; i < K; i++)
	{
		// 명령 확인
		int newRow = row, newCol = col;
		switch (moves[i])
		{
		case EAST:	newCol++;	break;
		case WEST:	newCol--;	break;
		case NORTH:	newRow--;	break;
		case SOUTH:	newRow++;	break;
		}
		// 불가능한 명령 무시
		if (!insideMap(newRow, newCol))
			continue;

		// 주사위 이동
		rollDice(moves[i]);
		row = newRow;
		col = newCol;

		// 값 복사
		if (map[row][col] == 0) {
			map[row][col] = dice.bot;
		}
		else {
			dice.bot = map[row][col];
			map[row][col] = 0;
		}

		// 출력
		cout << dice.top << '\n';
	}
}

int main() {
	input();
	solve();
	return 0;
}