#include <iostream>
#include <vector>
using namespace std;

vector<int> list;

void QuickSort(int left, int right){
	if (left < right) {
		int pivot = list[(left + right) / 2];
		int i = left, j = right;
		while (i <= j) {
			while (list[i] < pivot) i++;
			while (list[j] > pivot) j--;
			if (i <= j) {
				swap(list[i], list[j]);
				i++;
				j--;
			}
		}
		QuickSort(left, j);
		QuickSort(i, right);
	}
}

int main() {
	int N, t;
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> t;
		list.push_back(t);
	}

	QuickSort(0, N - 1);

	for (int i = 0; i < N; i++)
		cout << list[i] << '\n';

	return 0;
}