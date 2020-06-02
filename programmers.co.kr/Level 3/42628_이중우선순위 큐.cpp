#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
	priority_queue<int, vector<int>, less<int>> maxQ;
	priority_queue<int, vector<int>, greater<int>> minQ;
	int size = 0;

	for (auto& operation : operations) {
		char op = operation[0];
		int num = stoi(operation.substr(2));
		if (op == 'I') {
			maxQ.push(num);
			minQ.push(num);
			size++;
		}
		else {
			if (size == 0) 
				continue;
			if (size == 1) {
				while (!minQ.empty())
					minQ.pop();
				while (!maxQ.empty())
					maxQ.pop();
				size = 0;
				continue;
			}

			if (num == 1)
				maxQ.pop();
			else
				minQ.pop();

			size--;
		}
	}

	if (size > 0)
		return { maxQ.top(), minQ.top() };
	else
		return { 0, 0 };
}


void main() {
	solution({ "I 16", "D 1" });
	solution({ "I 7", "I 5", "I -5", "D -1" });
}