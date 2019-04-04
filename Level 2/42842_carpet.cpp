//https://programmers.co.kr/learn/courses/30/lessons/42842

#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int red) {
    int a = (brown+4)/2; // m+n
    int b = brown+red; // m*n
    // 이차방정식 근의 공식 활용
    int n = (a+sqrt(a*a-4*b))/2;
    int m = a-n;
    vector<int> answer;
    
    if(m>n){
        answer.push_back(m);
        answer.push_back(n);
    }
    else{
        answer.push_back(n);
        answer.push_back(m);
    }
    return answer;
}