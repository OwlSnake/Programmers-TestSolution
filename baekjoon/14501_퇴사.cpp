#include <iostream>
#include <algorithm>
using namespace std;

int N, maximumPay = 0;

struct schedule { int len; int pay; } s[16];

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> s[i].len >> s[i].pay;
}

void dfs(int day, int payment) {
	// 마지막 날까지 확인한 경우 탐색 종료
	if (day > N) {
		maximumPay = max(maximumPay, payment);
		return;
	}

	// 상담을 진행하지 않은 경우 탐색
	dfs(day + 1, payment);

	// 상담을 진행할 수 있는 경우 탐색
	if (day + s[day].len - 1 <= N)
		dfs(day + s[day].len, payment + s[day].pay);
	
}

void solve() {
	dfs(1, 0);
}

int main() {
	input();
	solve();
	cout << maximumPay;
	return 0;
}
