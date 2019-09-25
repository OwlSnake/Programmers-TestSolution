//https://programmers.co.kr/learn/courses/30/lessons/42584

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    for(int i=0; i<prices.size(); i++)
    {
        answer.push_back(0);
        for(int j=i+1; j<prices.size(); j++)
        {
            answer[i]++;
            if(prices[i]>prices[j])
                break;
        }
    }
    return answer;
}