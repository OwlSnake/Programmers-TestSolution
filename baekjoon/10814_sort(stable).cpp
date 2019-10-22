#include <iostream>
#include <algorithm>
using namespace std;

struct Member
{
	int age;
	string name;
};
Member arr[100001];

bool CompareMember(const Member& m1, const Member& m2) {
	return m1.age < m2.age;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i].age >> arr[i].name;

	stable_sort(arr, arr + N, CompareMember);

	for (int i = 0; i < N; i++)
		cout << arr[i].age << ' ' << arr[i].name << '\n';

	return 0;
}