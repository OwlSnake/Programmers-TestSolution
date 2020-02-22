#include <iostream>
#include <deque>
#include <string>
using namespace std;

struct turn {
	int idx, dir;
	turn(int i, int d) {
		idx = i; dir = d;
	}
};

deque<int> wheel[4];
int K;
deque<turn> turns;
int answer = 0;


void input() {
	for (int i = 0; i < 4; i++)
	{
		string line;
		cin >> line;
		for (int j = 0; j < 8; j++) {
			wheel[i].push_back(line[j] - '0');
		}
	}
	cin >> K;
	for (int i = 0; i < K; i++) {
		int idx, dir;
		cin >> idx >> dir;
		turns.push_back(turn(idx - 1, dir));
	}
}

void rotateWheel(int num, int dir) {
	if (dir == 1) {
		int t = wheel[num].back();
		wheel[num].pop_back();
		wheel[num].push_front(t);
	}
	else if (dir == -1) {
		int t = wheel[num].front();
		wheel[num].pop_front();
		wheel[num].push_back(t);
	}
}

void solve() {
	for (int i = 0; i < K; i++) {
	
		// 엮인 톱니 확인
		bool locked[3] = { wheel[0][2] != wheel[1][6], wheel[1][2] != wheel[2][6], wheel[2][2] != wheel[3][6] };
		deque<turn> newTurns;
		if (turns[i].idx == 0) {
			if (locked[0])								newTurns.push_back(turn(1, -turns[i].dir));
			if (locked[0] && locked[1])					newTurns.push_back(turn(2, turns[i].dir));
			if (locked[0] && locked[1] && locked[2])	newTurns.push_back(turn(3, -turns[i].dir));
		}
		else if (turns[i].idx == 1) {
			if (locked[0])								newTurns.push_back(turn(0, -turns[i].dir));
			if (locked[1])								newTurns.push_back(turn(2, -turns[i].dir));
			if (locked[1] && locked[2])					newTurns.push_back(turn(3, turns[i].dir));
		}
		else if (turns[i].idx == 2) {
			if (locked[0] && locked[1])					newTurns.push_back(turn(0, turns[i].dir));
			if (locked[1])								newTurns.push_back(turn(1, -turns[i].dir));
			if (locked[2])								newTurns.push_back(turn(3, -turns[i].dir));
		}
		else if (turns[i].idx == 3) {
			if (locked[0] && locked[1] && locked[2])	newTurns.push_back(turn(0, -turns[i].dir));
			if (locked[1] && locked[2])					newTurns.push_back(turn(1, turns[i].dir));
			if (locked[2])								newTurns.push_back(turn(2, -turns[i].dir));
		}

		rotateWheel(turns[i].idx, turns[i].dir);
		
		while (!newTurns.empty()) {
			rotateWheel(newTurns.front().idx, newTurns.front().dir);
			newTurns.pop_front();
		}
	}

	// 점수 계산
	answer = wheel[0].front() * 1 + wheel[1].front() * 2 + wheel[2].front() * 4 + wheel[3].front() * 8;
}
	

int main() {
	input();
	solve();

	cout << answer;

	return 0;
}
