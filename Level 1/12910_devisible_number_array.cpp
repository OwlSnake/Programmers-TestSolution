//https://programmers.co.kr/learn/courses/30/lessons/12910

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    
    for(int i=0; i<arr.size(); i++)
        if(arr[i]%divisor == 0)
            answer.push_back(arr[i]);
    
    if(answer.empty())
        return {-1};
    
    sort(answer.begin(), answer.end());
    
    return answer;
}