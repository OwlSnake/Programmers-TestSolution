#include <iostream>

using namespace std;

int main() {
	int x;
	cin >> x;
	
	for (int i = 1; ; i++) {

		// 이 때 i+1이 분자, 분모의 합이 된다
		if (x <= i) {
			// 방향이 지그재그 순서로 바뀐다
			if (i % 2 == 0) 
				cout << x << '/' << i+1-x;
			else 
				cout << i+1-x << '/' << x;
			
			break;
		}			
		x -= i;
	}
	return 0;
}
