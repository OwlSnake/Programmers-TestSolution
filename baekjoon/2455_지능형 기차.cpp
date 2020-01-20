#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int answer = 0;

	for (int i = 0; i < 4; i++)
	{
		int in, out, t;
		cin >> out >> in;
		t = answer - out + in;

		answer = max(answer, t);
	}
	cout << answer;
	return 0;
}