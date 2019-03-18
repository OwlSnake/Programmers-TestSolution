//https://programmers.co.kr/learn/courses/30/lessons/12916

#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    int pCounter = 0, yCounter = 0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='p' || s[i]=='P') pCounter++;
        if(s[i]=='y' || s[i]=='Y') yCounter++;
    }
    
    return pCounter == yCounter;
}