// https://programmers.co.kr/learn/courses/30/lessons/12973

#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    vector<char> stack;
    stack.push_back(s[0]);
    
    for(int i=1; i<s.size(); i++){
        if(stack.back()==s[i])
            stack.pop_back();
        else
            stack.push_back(s[i]);
    }
    return stack.empty();
}