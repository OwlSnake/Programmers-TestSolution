//https://programmers.co.kr/learn/courses/30/lessons/12943

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int num) {
    int answer = 0;
    while(num != 1)
    {
        num = (num%2==0) ? num/2 : num*3+1;
        
        if(answer >= 450)
            return -1;
        else 
            answer++;
    }
    return answer;
}