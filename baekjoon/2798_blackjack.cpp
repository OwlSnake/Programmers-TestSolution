#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, M, max = 0;
	cin >> N >> M;
	vector<int> cards;

	for (int i = 0; i < N; i++)
	{
		int t;
		cin >> t;
		cards.push_back(t);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++) {
			if (j == i)
				continue;

			for (int k = 0; k < N; k++) {
				if (k == i || k == j)
					continue;
				
				int sum = cards[i] + cards[j] + cards[k];
				if (sum > max && sum <= M)
					max = sum;
			}
		}
	}

	cout << max;

	return 0;
}	
 