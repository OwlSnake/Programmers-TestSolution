#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> stack;

bool StackHas(int num) {
	for (int i = 0; i < stack.size(); i++)
		if (stack[i] == num)
			return true;
	return false;
}

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
		if (!StackHas(i)) {
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
