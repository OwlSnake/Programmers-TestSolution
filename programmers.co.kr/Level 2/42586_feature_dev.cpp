//https://programmers.co.kr/learn/courses/30/lessons/42586

#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> days;
    int count = 1;
    
    for(int i=0; i<progresses.size(); i++)
    {
        progresses[i] = 100 - progresses[i];
        days.push_back(ceil((float)progresses[i]/speeds[i]));
    }
    
    int past_days = days[0], task = 0;
    for(int i=0; i<days.size(); i++)
    {
        if(days[i]>past_days)
        {
            past_days = days[i];
            answer.push_back(task);
            task = 1;
        }
        else
            task++;
        
        if(i==days.size()-1)
            answer.push_back(task);
    }
    return answer;
}