/*예제1에서 한 줄씩 **빈 칸의 위치**를 살펴보면 다음과 같다.
* 0: 없음 
* 1: 3으로 나눈 나머지가 1인 열에 빈칸 (1, 4, 7...) => **(i%3 == 1)**
* 2: 없음

* 3: (i%3 == 1)
* 4: (i%3 == 1) && (**i/3**%3 == 1)
* 5: (i%3 == 1)

* 6: 없음
* 7: (i%3 == 1)
* 8: 없음

따라서 별이 찍히지 않는 경우의 좌표에는  
1. (i % 3 == 1) && (j % 3 == 1)
1. (i/3 % 3 == 1) && (j/3 % 3 == 1)
1. (i/9 % 3 == 1) && (j/9 % 3 == 1)
1. (i/27 % 3 == 1) && (j/27 % 3 == 1)
..
이런 규칙이 있음을 알 수 있다.

이를 바탕으로 (i, j)위치에 별을 표시할 지 결정하는 CheckChar 함수를 정의할 수 있고. 문제를 해결할 수 있다.*/


#include <iostream>
using namespace std;

// (i, j)위치에 별을 찍을 지 확인하는 함수
char CheckChar(int i, int j, int size) {
	while (size > 0) {
		if (i / size % 3 == 1 && j / size % 3 == 1)
			return ' ';
		size /= 3;
	}
	return '*';
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << CheckChar(i, j, n);
		}
		cout << '\n';
	}
	return 0;
}