//https://programmers.co.kr/learn/courses/30/lessons/12953

#include <string>
#include <vector>

using namespace std;

int getGcd(int a, int b){
    int temp;
    while(b>0){
        temp = b;
        b = a%b;
        a = temp;
    }
    return a; 
}
int getLcm(int a, int b){
    return a*b/getGcd(a,b);
}

int solution(vector<int> arr) {
    int answer = 1;
    for(int num : arr)
        answer = getLcm(answer, num);
    return answer;
}