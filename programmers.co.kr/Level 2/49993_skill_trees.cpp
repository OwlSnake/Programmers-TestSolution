//https://programmers.co.kr/learn/courses/30/lessons/49993


#include <string>
#include <vector>

using namespace std;

bool isTreeValid(string tree, string order){
    int i = 0;
    for(char skill : tree){
        if(order.find(skill)==string::npos)
            continue;
        else{
            if(skill == order[i])
                i++;
            else
                return false;
        }
    }
    return true;
}

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    for(string str : skill_trees){
        if(isTreeValid(str, skill))
            answer++;
    }
    return answer;
}
