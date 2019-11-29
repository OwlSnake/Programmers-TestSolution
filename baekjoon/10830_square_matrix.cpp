#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> mat;

mat operator * (const mat &A, const mat &B) {
	const int size = A.size();
	mat result(size, vector<int>(size));
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			int sum = 0;
			for (int k = 0; k < size; k++)
				sum += A[i][k] * B[k][j];
			result[i][j] = sum % 1000;
		}
	}
	return result;
}

void PrintMat(const mat M) {
	const int size = M.size();
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			cout << M[i][j] % 1000 << ' ';
		cout << '\n';
	}
}

mat Recur(const mat& A, long long expo) {
	if (expo == 1)
		return A;

	mat temp = Recur(A, expo / 2);
	if (expo % 2)
		return temp * temp * A;
	else
		return temp * temp;
}

void Solve()
{
	int N;
	long long B;
	cin >> N >> B;
	mat A(N, vector<int>(N));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> A[i][j];

	PrintMat(Recur(A, B));
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	Solve();
	return 0;
}