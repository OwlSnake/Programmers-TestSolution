// https://programmers.co.kr/learn/courses/30/lessons/12939
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> nums;
    istringstream iss(s);
    string token;
    
    // 문자열 나누어서 vector에 저장
    while(getline(iss, token, ' '))
        nums.push_back(stoi(token));
    
    answer += to_string(*min_element(nums.begin(), nums.end())) + " ";
    answer += to_string(*max_element(nums.begin(), nums.end()));
    return answer;
}