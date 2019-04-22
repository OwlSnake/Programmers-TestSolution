// https://programmers.co.kr/learn/courses/30/lessons/12980
using namespace std;

int solution(int n)
{
    int answer = 0;
    while(n>0){
        if(n%2==1)
            answer++;
        n/=2;
    }
    return answer;
}