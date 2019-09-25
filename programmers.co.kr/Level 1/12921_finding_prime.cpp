//https://programmers.co.kr/learn/courses/30/lessons/12921

#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool IsPrime(int x)
{
    if(x<=3) return true;
    if(x%2==0 || x%3==0) return false;
    for(int i=5; i*i<=x; i+=6)
    {
        if(x%i==0 || x%(i+2)==0) return false;
    }
    return true;
}

int solution(int n) {
    int answer = 0;
    for(int i=2; i<=n; i++)
    {
        if(IsPrime(i)) 
        {
            answer++;
        }
    }
    return answer;
}