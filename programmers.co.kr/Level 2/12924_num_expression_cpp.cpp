// https://programmers.co.kr/learn/courses/30/lessons/12924
#include <string>
#include <vector>

using namespace std;


int solution(int n) {
    int answer = 1; // 항상 1개의 자연수로 표현 가능
    int curDiv = 2, divSum = 3;
    
    while(divSum <= n){
        if(curDiv%2==0){ // 짝수일 경우
            if(n*2%curDiv==0 &&  (n*2/curDiv)%2==1)
                answer++;  
        }
        else{ // 홀수일 경우
            if(n%curDiv==0)
                answer++;  
        }
        curDiv++;
        divSum += curDiv;
    }
    return answer;
}