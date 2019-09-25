//https://programmers.co.kr/learn/courses/30/lessons/42578

#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> clothMap;
    
    for(vector<string> cloth : clothes)
    {
        if(clothMap.count(cloth[1])!=0)
            clothMap[cloth[1]] += 1;
        else
            clothMap.insert({cloth[1], 1});
    }
    for(auto const& [key, val] : clothMap)
    {
        answer *= (val + 1);
    }
    return answer - 1;
}