#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> stack;

void PrintStack() {
	for (int i = 0; i < stack.size(); i++)
		cout << stack[i] << ' ';
	cout << '\n';
}

void BackTracking() {
	if (stack.size() == M) {
		PrintStack();
		stack.pop_back();
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		if (stack.size() == 0 || stack.back() <= i)
		{
			stack.push_back(i);
			BackTracking();
		}
	}
	if(stack.size() > 0)
		stack.pop_back();
}

int main() 
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;

	BackTracking();

	return 0;
}
