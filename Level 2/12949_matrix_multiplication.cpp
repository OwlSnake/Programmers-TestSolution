// https://programmers.co.kr/learn/courses/30/lessons/12949

#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    vector<int>answerRow;
    int temp = 0;
    for(int i=0; i<arr1.size(); i++){
        for(int j=0; j<arr2[0].size(); j++){
            // Gets value of answer[i][j] here
            for(int k=0; k<arr2.size(); k++){
                temp += arr1[i][k]*arr2[k][j];
            }
            answerRow.push_back(temp);
            temp = 0;
        }
        answer.push_back(answerRow);
        answerRow.clear();
    }
    return answer;
}