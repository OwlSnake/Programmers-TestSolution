//https://programmers.co.kr/learn/courses/30/lessons/42587

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1;
    while(true)
    {
        if(priorities[0]>=*max_element(priorities.begin(), priorities.end()))
        {
            // 맨 앞의 요청 출력
            if(location==0)
                return answer;
            else
            {
                priorities.erase(priorities.begin());
                answer++;
                location--;
            }
        }
        else
        {
            // 목록 뒤로 보냄
            if(location==0)
                location += priorities.size();

            priorities.push_back(priorities[0]);
            priorities.erase(priorities.begin());
            location--;
        }
    }
}