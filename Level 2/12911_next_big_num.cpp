//https://programmers.co.kr/learn/courses/30/lessons/12911

#include <string>
#include <vector>

using namespace std;

int getBinaryCount(int n)
{
    // n을 이진수로 바꾸었을 때 1의 갯수를 구한다
    int count = 0;
    while(n > 0)
    {
        if(n%2 == 1)
            count += 1;
        n /= 2;
    }
    return count;
}

int solution(int n) {
    int nBinaryCount = getBinaryCount(n);
    // n보다 큰 수 중 가장 작은, 조건을 만족하는 i를 찾는다
    for(int i=n+1; ;i++)
    {
        if(getBinaryCount(i) == nBinaryCount)
            return i;
    }
}