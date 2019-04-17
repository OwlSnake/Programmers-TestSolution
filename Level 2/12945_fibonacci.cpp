// https://programmers.co.kr/learn/courses/30/lessons/12945?language=cpp

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int F(int n)
{
    int n1 = 0, n2 = 1, current = 1;
    for(int i=2; i<=n; i++)
    {
        current = (n1 + n2)%1234567;
        n1 = n2;
        n2 = current;
    }
    return current;
}

int solution(int n) {
    return F(n);
}