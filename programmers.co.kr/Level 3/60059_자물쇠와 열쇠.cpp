#include <string>
#include <vector>

#include <iostream>

using namespace std;

typedef vector<vector<int>> mat;

mat k[4];
int M, N;

void printmat(mat mat) {
	for (auto row : mat) {
		for (int elem : row)
			cout << elem << " ";
		cout << endl;
	}
	cout << endl;
}

bool check(const mat& key, const mat& lock, int offsetR, int offsetC) {
	for (int r = 0; r < N; r++){
		for (int c = 0; c < N; c++) {
			if (r - offsetR < 0 || r - offsetR >= M || c - offsetC < 0 || c - offsetC >= M) {
				if (lock[r][c] == 0)
					return false;
			}
			else {
				if (lock[r][c] == key[r - offsetR][c - offsetC])
					return false;
			}
		}
	}
	return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {

	M = key.size();
	N = lock.size();
	for (int i = 0; i < 4; i++) {
		k[i] = key;
	}
	
	// key 회전
	for (int r = 0; r < M; r++) {
		for (int c = 0; c < M; c++) {
			k[1][M - 1 - c][r] = k[0][r][c];
			k[2][M - 1 - r][M - 1 - c] = k[0][r][c];
			k[3][c][M - 1 - r] = k[0][r][c];
		}
	}

	// 위치별 key 4개 확인
	for (int r = 1-M; r < N; r++){
		for (int c = 1 - M; c < N; c++) {
			cout << "checking " << r << ", " << c << endl;
			for (int i = 0; i < 4; i++){

				if (check(k[i], lock, r, c)) {
					printmat(k[i]);
					printmat(lock);
					cout << "key " << i << endl;
					return true;
				}
			}
		}
	}
	return false;
}

void main(){
	solution({ {0,0,0},{1,0,0},{0,1,1} }, { {1,1,1},{1,1,0},{1,0,1} });

}