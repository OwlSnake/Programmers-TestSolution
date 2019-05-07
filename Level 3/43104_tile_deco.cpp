https://programmers.co.kr/learn/courses/30/lessons/43104

#include <string>
#include <vector>
using namespace std;

long long solution(int N) {
    long long answer = 0;
    vector<long long> rectLen;
    rectLen.push_back(1);
    rectLen.push_back(1);
    // Get length of rectangle (which is i'th fibbonaci number)
    for(int i=2; i<N+1; i++){
        rectLen.push_back(rectLen[i-1] + rectLen[i-2]);
    }
    answer = (rectLen[N-1]+rectLen[N])*2;
    return answer;
}