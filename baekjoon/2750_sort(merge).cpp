#include <iostream>
#include <vector>
using namespace std;

vector<int> MergeSort(vector<int> list, int first, int last) {
	int mid = (first + last) / 2;
	vector<int> left, right, result;
	if (first < last) {
		left = MergeSort(list, first, mid);
		right = MergeSort(list, mid + 1, last);

		int i = 0, j = 0;
		while (i < left.size() && j < right.size()) {
			if (left[i] < right[j])
				result.push_back(left[i++]);
			else
				result.push_back(right[j++]);
		}
		while (i < left.size())
			result.push_back(left[i++]);
		while (j < right.size())
			result.push_back(right[j++]);
	}
	else
		result.push_back(list[first]);

	return result;
}

int main() {
	int N;
	vector<int> list;
	cin >> N;
	for (int i = 0; i < N; i++){
		int t;
		cin >> t;
		list.push_back(t);
	}

	list = MergeSort(list, 0, N - 1);

	for (int i = 0; i < N; i++)
		cout << list[i] << '\n';

	return 0;
}