#include <iostream>

using namespace std;

int main() {
	int x;
	cin >> x;
	
	for (int i = 1; ; i++) {

		// �� �� i+1�� ����, �и��� ���� �ȴ�
		if (x <= i) {
			// ������ ������� ������ �ٲ��
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
