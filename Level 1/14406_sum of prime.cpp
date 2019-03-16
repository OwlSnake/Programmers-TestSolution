// https://programmers.co.kr/learn/courses/30/lessons/14406

#include <vector>

using namespace std;

long long solution(int N) {
    bool isPrime[N+1];
    long long answer = 0;

    for(int i=2; i<=N; i++)
        isPrime[i] = true;

    for(int i=2; i*i<N; i++)
    {
        if(isPrime[i])
        {
            for(int j=i*i; j<=N; j+=i)
                isPrime[j] = false;
        }
    }

    for(int i=2; i<=N; i++)
        if(isPrime[i])
            answer += i;
    return answer;
}
