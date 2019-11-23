#include <iostream>
#include <string>
#include <deque>
using namespace std;

deque<int> q;

void PrintDeque(deque<int> q, bool reversed) {
	if (q.empty()) {
		cout << "[]";
		return;
	}

	cout << "[";
	if (!reversed) {
		for (int i = 0; i < q.size() - 1; i++)
			cout << q[i] << ",";
		cout << q[q.size() - 1] << "]";
	}
	else {
		for (int i = q.size()-1; i > 0; i--)
			cout << q[i] << ",";
		cout << q[0] << "]";
	}
}


void Solve()
{
	string func, arrStr;
	int N, num;
	bool isReversed = false;

	cin >> func;
	cin >> N;
	cin >> arrStr;

	// Parse input, and push into deque
	int numIdx = 1;
	q.clear();
	for (int i = 1; i < arrStr.size(); i++)
	{
		if (arrStr[i] == ',') {
			q.push_back(stoi(arrStr.substr(numIdx, i - numIdx)));
			numIdx = i + 1;
		}
		else if (arrStr[i] == ']' && N > 0) {
			q.push_back(stoi(arrStr.substr(numIdx, i - numIdx)));
		}
	}

	// Check input deque size
	if (q.size() != N) {
		cout << "error\n";
		return;
	}

	// Run each function
	for (int i = 0; i < func.size(); i++)
	{
		if (func[i] == 'R') {
			isReversed = !isReversed;
		}
		else if(func[i] == 'D') {
			if (q.empty()) {
				cout << "error\n";
				return;
			}

			if (isReversed) 
				q.pop_back();
			else
				q.pop_front();
		}
		else {
			cout << "error\n";
			return;
		}
	}

	// Print result
	PrintDeque(q, isReversed);
	cout << '\n';
}



int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	while(T--)
		Solve();
	return 0;
}