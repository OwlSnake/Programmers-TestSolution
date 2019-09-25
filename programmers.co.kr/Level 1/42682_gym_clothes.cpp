//https://programmers.co.kr/learn/courses/30/lessons/42862

#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    map<int, int> status;
    
    for(int i=1; i<=n; i++)
        status.insert(make_pair(i, 1));
    // 여분이 있는 학생들
    for(auto elem : reserve)
        if(status.count(elem)!=0)
            status[elem]++;
    // 잃어버린 학생들
    for(auto elem : lost)
        if(status.count(elem)!=0)
            status[elem]--;

    // 빌려줄 수 있으면 아무나 빌려준다
    for(int i=1; i<=n; i++)
    {
        if(status[i]==2)
        {
            if(status[i-1]>0 && status[i+1]>0) // 둘 다 있는 경우. 빌려 줄 수 없음
                continue;
            if(status[i-1]==0) // 앞사람에게 줌
            {
                status[i]--;
                status[i-1]++;
            }
            else // 뒷사람에게 줌
            {
                status[i]--;
                status[i+1]++;
            }
        }
    }
    // 체육복을 가진 사람을 센다
    for(int i=1; i<=n; i++)
        if(status[i]>0)
            answer++;
    
    return answer;
}