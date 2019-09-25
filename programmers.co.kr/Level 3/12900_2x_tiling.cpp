//https://programmers.co.kr/learn/courses/30/lessons/12900

using namespace std;

int solution(int n) {
    int a = 1, b = 2, t;
    if(n <= 3) return n;
    for(int i = 3; i <= n; i++){
        t = b;
        b = (a+b)%1000000007;
        a = t;
    }
    return b;
}