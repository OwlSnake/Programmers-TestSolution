//https://programmers.co.kr/learn/courses/30/lessons/42588

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer = heights;
    for(int i=heights.size()-1; i>=0; i--)
    {
        answer[i] = 0;
        for(int j=i-1; j>=0; j--)
        {
            cout<<heights[i]<<" "<<heights[j]<<endl;
            if(heights[j]>heights[i])
            {
                answer[i] = j+1;
                break;
            }
        }
    }
    return answer;
}