#include <iostream>
using namespace std;

class Queue {
private:
	static const int MAX_SIZE = 10000;
	int arr[MAX_SIZE];
	int f = 0, b = 0;
public:
	void push(int num) {
		arr[b++] = num;
	}
	int pop() {
		if (f == b)
			return -1;
		return arr[f++];
	}
	int size() {
		if (f <= b)
			return b - f;
		else
			return b + MAX_SIZE - f;
	}
	int empty() {
		if (f == b)
			return 1;
		else
			return 0;
	}
	int front() {
		if (f == b)
			return -1;
		else
			return arr[f];
	}
	int back() {
		if (f == b)
			return -1;
		else 
			return arr[b - 1];
	}
};

Queue queue;

void Solve()
{
	int N, t;
	cin >> N;
	string op;
	for (int i = 0; i < N; i++) {
		cin >> op;
		if (op == "push") {
			int num;
			cin >> num;
			queue.push(num);
		}
		else if (op == "pop") 
			cout << queue.pop() << '\n';
		else if (op == "size") 
			cout << queue.size() << '\n';
		else if (op == "empty")
			cout << queue.empty() << '\n';
		else if (op == "front")
			cout << queue.front() << '\n';
		else if (op == "back")
			cout << queue.back() << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	Solve();
	return 0;
}