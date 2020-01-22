#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int height[9], sum = 0;
	const int MAX = 101;
	bool found = false;
	for (int i = 0; i < 9; i++)
	{
		cin >> height[i];
		sum += height[i];
	}

	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (sum - 100 == height[i] + height[j]) {
				height[i] = MAX;
				height[j] = MAX;
				found = true;
				break;
			}
		}
		if (found)
			break;
	}

	sort(height, height + 9);

	for (int i = 0; i < 9; i++)
	{
		if (height[i] != MAX)
			cout << height[i] << '\n';
	}

	return 0;
}