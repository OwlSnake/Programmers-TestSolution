//https://programmers.co.kr/learn/courses/30/lessons/12950

#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    vector<int> tempMatrix;
    
    for(int i=0; i<arr1.size(); i++)
    {
        for(int j=0; j<arr1[i].size(); j++)
            tempMatrix.push_back(arr1[i][j]+arr2[i][j]);
        
        answer.push_back(tempMatrix);
        tempMatrix.clear();
    }
    return answer;
}