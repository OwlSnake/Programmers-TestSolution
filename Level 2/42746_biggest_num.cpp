//https://programmers.co.kr/learn/courses/30/lessons/42746

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool strLess(string s1, string s2)
{
    string t1 = s1+s2, t2 = s2+s1;
    return stoi(t1) > stoi(t2);
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> strings;

    for(int num : numbers)
        strings.push_back(to_string(num));
    
    sort(strings.begin(), strings.end(), strLess);
    
    for(string str : strings)
        answer += str;
    
    if(answer.front() == '0')
        return "0";

    return answer;
}