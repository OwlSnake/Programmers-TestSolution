//https://programmers.co.kr/learn/courses/30/lessons/12947

#include <string>
#include <vector>

using namespace std;

int getDigitSum(int num)
{
    int result = 0;
    while(num > 0)
    {
        result += num%10;
        num /= 10;
    }
    return result;
}

bool solution(int x) {
    if(x % getDigitSum(x) == 0)
        return true;
    else
        return false;
}