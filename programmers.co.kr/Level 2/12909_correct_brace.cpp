//https://programmers.co.kr/learn/courses/30/lessons/12909

#include <string>

using namespace std;

bool solution(string s)
{
    // 열린 괄호의 수
    int braceCount = 0;
    for(char c : s)
    {
        if(c=='(')
            braceCount += 1;
        else
            braceCount -= 1;
        // 열린 괄호의 수는 0보다 작을 수 없지만
        if(braceCount < 0)
            return false;
    }
    // 마지막에는 0이 되어야 한다
    return braceCount==0;
}