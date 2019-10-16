#include <iostream>
#include <string>
using namespace std;

int main(){
	int N, M, diff1, diff2, diff_min = 64;
	cin >> N >> M;

	string board[50];

	for (int i = 0; i < N; i++)
		cin >> board[i];
	
	// 8*8�� ���� �� �ִ� ����� ���� ��� Ȯ���Ѵ�
	for (int i = 0; i <= N-8; i++) {
		for (int j = 0; j <= M-8; j++){

			diff1 = 0;
			diff2 = 0;

			// 8*8�� ���� ������ diff�� ���Ѵ�
			for (int k = i; k < i + 8; k++) {
				for (int l = j; l < j + 8; l++) {
					if ((k + l) % 2 == 0) {
						if (board[k][l] == 'W')
							diff2++;
						else
							diff1++;
					}
					if ((k + l) % 2 == 1) {
						if (board[k][l] == 'W')
							diff1++;
						else
							diff2++;
					}
				}
			}
			if (diff1 < diff_min)
				diff_min = diff1;
			if (diff2 < diff_min)
				diff_min = diff2;
		}
	}

	cout << diff_min;

	return 0;
}