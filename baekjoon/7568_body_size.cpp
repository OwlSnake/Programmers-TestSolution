#include <iostream>
#include <vector>
using namespace std;

int main(){
	int N;
	cin >> N;

	vector<int> weights, heights, ranks;

	for (int i = 0; i < N; i++){

		int x, y;
		cin >> x >> y;
		weights.push_back(x);
		heights.push_back(y);
		ranks.push_back(1);
	}

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){

			if (j == i)
				continue;

			if (weights[i] < weights[j] && heights[i] < heights[j]) 
				ranks[i]++;
		}
	}

	for (int i = 0; i < N; i++)
		cout << ranks[i] << ' ';

	return 0;
}
 