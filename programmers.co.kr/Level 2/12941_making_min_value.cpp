// https://programmers.co.kr/learn/courses/30/lessons/12941

#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    // 두 배열을 정렬한 뒤, 반대 방향으로 더해 나간다
    int answer = 0, len = A.size();
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    for(int i=0; i<len; i++)
        answer += A[i]*B[len-i-1];
    
    return answer;
}