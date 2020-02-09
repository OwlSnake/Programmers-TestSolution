#include <iostream>
#include <vector>
using namespace std;

int N, B, C;
vector<int> room;
long long answer = 0;


void input() {
	cin >> N;
	room.resize(N);
	for (int i = 0; i < N; i++)
		cin >> room[i];
	cin >> B >> C;
}

void solve() {
	for (int i = 0; i < N; i++)
	{
		room[i] -= B;
		if (room[i] < 0)
			room[i] = 0;
	}
	answer += N;

	for (int i = 0; i < N; i++)
	{
		if (room[i] % C == 0)
			answer += room[i] / C;
		else
			answer += room[i] / C + 1;
	}
}

int main() {
	input();
	solve();
	cout << answer;
	return 0;
}