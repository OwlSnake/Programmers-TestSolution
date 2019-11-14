#include <iostream>
#include <vector>
using namespace std;

int N, p[21][21];
bool isTeam1[21];

int minPowerGap = 1000000000;

int CalcPowerGap() {
	int power1 = 0, power2 = 0;
	vector<int> team1, team2;

	for (int i = 1; i <= N; i++) {
		if (isTeam1[i])
			team1.push_back(i);
		else
			team2.push_back(i);
	}

	for (int i = 0; i < N/2; i++)
	{
		for (int j = i+1; j < N/2; j++)
		{
			power1 += p[team1[i]][team1[j]] + p[team1[j]][team1[i]];
			power2 += p[team2[i]][team2[j]] + p[team2[j]][team2[i]];
		}
	}
	return abs(power1 - power2);
}

void MakeTeam(int curMem, int memberCount) {
	if (memberCount == N / 2) {
		int powerGap = CalcPowerGap();
		minPowerGap = (minPowerGap > powerGap) ? powerGap : minPowerGap;
		return;
	}
	for (int i = curMem + 1; i <= N; i++)
	{
		if (!isTeam1[i]) {
			isTeam1[i] = true;
			MakeTeam(i, memberCount + 1);
			isTeam1[i] = false;
		}
	}
}

int main() 
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> p[i][j];

	MakeTeam(0, 0);
	cout << minPowerGap;

	return 0;
}
