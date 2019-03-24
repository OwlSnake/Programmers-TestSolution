//https://programmers.co.kr/learn/courses/30/lessons/12982

#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    sort(d.begin(), d.end(), greater<int>());
    while(true)
    {
        if(!d.empty() && budget - d.back() >= 0)
        {
            budget -= d.back();
            d.pop_back();
            answer++;
        }
        else
            break;
    }
    return answer;
}