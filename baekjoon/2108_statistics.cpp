#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int num_count[8001];

int main() {
	vector<int> list;
	int N, t;
	double avg;
	int median, mode, range, mode_count = 0, sum = 0;
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> t;
		list.push_back(t);
		sum += t;
		num_count[t + 4000]++;
	}

	sort(list.begin(), list.end());
	range = list.back() - list.front();
	median = list[N / 2];
	avg = (double)sum / N;

	for (int i = 0; i < 8001; i++) {
		if (num_count[i] == 0) continue;
		if (num_count[i] > mode_count) {
			mode_count = num_count[i];
			mode = i - 4000;
		}
	}

	vector<int> mode_list;
	for (int i = 0; i < 8001; i++)
		if (num_count[i] == mode_count && mode_list.size()<2)
			mode_list.push_back(i - 4000);
	if (mode_list.size() > 1)
		mode = mode_list[1];
	
	printf("%.0f\n%d\n%d\n%d\n", avg, median, mode, range);

	return 0;
}
