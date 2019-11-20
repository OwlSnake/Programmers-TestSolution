#include <iostream>
using namespace std;

class Stack {
private:
	int stack[10000];
	int size = 0;

public:
	void Push(int x) {
		stack[size] = x;
		size++;
	}
	void Pop() {
		if (size == 0)
			cout << -1;
		else {
			cout << stack[size - 1];
			size--;
		}
	}
	void Size() {
		cout << size;
	}
	void Empty() {
		if (size == 0)
			cout << 1;
		else
			cout << 0;
	}
	void Top() {
		if (size == 0)
			cout << -1;
		else
			cout << stack[size - 1];
	}
};

Stack s;

void Solve()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string inst;
		cin >> inst;
		if (inst == "push") {
			int num;
			cin >> num;
			s.Push(num);
			continue;
		}
		else if (inst == "pop")
			s.Pop();
		else if (inst == "size")
			s.Size();
		else if (inst == "empty")
			s.Empty();
		else if (inst == "top")
			s.Top();
		cout << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	Solve();
	return 0;
}