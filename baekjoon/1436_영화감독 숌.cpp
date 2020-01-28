#include <iostream>
#include <string>
using namespace std;

bool Check666(int n) {
	string s = to_string(n);
	for (int i = 0; i <= s.size() - 3; i++) {
		if (s[i] == '6' && s[i + 1] == '6' && s[i + 2] == '6' )
			return true;
	}
	return false;
}

int main(){
	int N, count = 0;;
	cin >> N;

	for (int i = 666; ; i++) {
		if (Check666(i))
			count++;
		
		if (count == N) {
			cout << i;
			break;
		}
	}
	return 0;
}