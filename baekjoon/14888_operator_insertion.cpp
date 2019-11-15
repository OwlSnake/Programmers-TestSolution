#include <iostream>
using namespace std;

int N;
int num[101], op[100];
int opCount[4];
int mx = -1000000000, mn = 1000000000;

int Calc() {
	int result = num[0];
	for (int i = 1; i < N; i++)
	{
		if (op[i-1] == 1)
			result += num[i];
		else if (op[i-1] == 2)
			result -= num[i];
		else if (op[i-1] == 3)
			result *= num[i];
		else if (op[i-1] == 4)
			result /= num[i];
	}
	return result;
}

void FillOpArray(int i) {
	for (int type = 0; type < 4; type++)
	{
		if (opCount[type] > 0) {
			
			opCount[type]--;
			op[i] = type + 1;
			FillOpArray(i + 1);
			opCount[type]++;
		}
	}
	int result = Calc();
	mx = (result > mx) ? result : mx;
	mn = (result < mn) ? result : mn;
}

int main() 
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> num[i];
	for (int i = 0; i < 4; i++)
		cin >> opCount[i];

	FillOpArray(0);

	cout << mx << '\n' << mn;

	return 0;
}
