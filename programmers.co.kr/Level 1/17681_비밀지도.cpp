#include <string>
#include <vector>

#include <iostream>

using namespace std;

vector<string> answer;

string convertToStr(int num, int size) {
	string result;
	while (num > 0) {
		if (num % 2 == 0)
			result = ' ' + result;
		else
			result = '#' + result;
		num /= 2;
	}
	while (result.length() < size)
		result = ' ' + result;
    
	return result;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;
	for (int i = 0; i < n; i++)
    {
		arr1[i] = arr1[i] | arr2[i];
		answer.push_back(convertToStr(arr1[i], n));
	}
	return answer;
}