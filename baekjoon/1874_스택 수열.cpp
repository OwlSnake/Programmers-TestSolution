#include <iostream>
#include <vector>
using namespace std;

vector<char> result;
vector<int> stack;

void Solve()
{
	int N, nextNum, lastNum = 1;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> nextNum;

		if (nextNum >= lastNum) {
			for (int j = lastNum; j <= nextNum; j++)
			{
				stack.push_back(j);
				result.push_back('+');
			}
			stack.pop_back();
			result.push_back('-');

			lastNum = nextNum + 1;
		}
		else if(nextNum == stack.back()){
			stack.pop_back();
			result.push_back('-');
		}
		else {
			cout << "NO";
			return;
		}
	}

	for (int i = 0; i < result.size(); i++)
		cout << result[i] << '\n';
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	Solve();
	return 0;
}