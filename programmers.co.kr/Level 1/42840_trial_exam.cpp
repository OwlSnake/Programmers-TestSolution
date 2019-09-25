//https://programmers.co.kr/learn/courses/30/lessons/42840

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> point = {0, 0, 0};
    
    vector<int> test1 = {1,2,3,4,5};
    vector<int> test2 = {2,1,2,3,2,4,2,5};
    vector<int> test3 = {3,3,1,1,2,2,4,4,5,5};
    
    for(int i=0; i<answers.size(); i++)
    {              
        if(answers[i]==test1[i%test1.size()]) point[0]++;
        if(answers[i]==test2[i%test2.size()]) point[1]++;
        if(answers[i]==test3[i%test3.size()]) point[2]++;
    }
    
    int maxPoint = *max_element(point.begin(), point.end());
    
    for(int i=0; i<point.size(); i++)
    {
        if(point[i]==maxPoint) answer.push_back(i+1);
    }
    return answer;
}