//https://programmers.co.kr/learn/courses/30/lessons/12931

using namespace std;

int solution(int n)
{
    int answer = 0;
    while(n>=10)
    {
        answer += n%10;
        n /= 10;
    }

    return answer+n;
}