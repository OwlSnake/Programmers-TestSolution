#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class heap {
private:
	vector<int> list;
public:
	heap() {
		// heap index should starts form 1
		list.push_back(INT_MAX);
	}
	void insert(int n) {
		// add to back
		list.push_back(n);

		// sort upward
		int i = list.size() - 1;
		while (i > 1 && list[i] > list[i/2]) {
			swap(list[i], list[i / 2]);
			i /= 2;
		}
	}
	int pop() {
		if (list.size() == 1)
			return 0;

		// replace root with last element
		int root = list[1];
		list[1] = list.back();
		list.pop_back();

		// sort downward
		int i = 1;
		while (i * 2 < list.size()) {
			int largerChild = i * 2;
			if (i * 2 + 1 < list.size() && list[i * 2] < list[i * 2 + 1])
				largerChild = i * 2 + 1;

			if (list[i] < list[largerChild])
				swap(list[i], list[largerChild]);
			else
				break;

			i = largerChild;
		}
		return root;
	}
	int size() {
		return list.size() - 1;
	}
	void print() {
		cout << "[ ";
		for (int i = 1; i < list.size(); i++)
			cout<< list[i] << ' ';
		cout << "]\n";
	}
};

heap h = heap();

void Solve()
{
	int N, t;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> t;
		if (t == 0)
			cout << h.pop() << "\n";
		else
			h.insert(t);
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	Solve();
	return 0;
}