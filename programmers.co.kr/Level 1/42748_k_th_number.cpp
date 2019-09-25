//https://programmers.co.kr/learn/courses/30/lessons/42748

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> sub_array;
    for(int i=0; i<commands.size(); i++)
    {
        sub_array = vector<int>(array.begin()+commands[i][0]-1, array.begin()+commands[i][1]);
        sort(sub_array.begin(), sub_array.end());
        answer.push_back(sub_array[commands[i][2]-1]);
    }
    return answer;
}