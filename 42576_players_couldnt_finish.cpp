//https://programmers.co.kr/learn/courses/30/lessons/42576

#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    map<string, int> names;
    // Insert completed player's name in map.
    for(auto elem : completion)
    {
        if(names.count(elem)!=0)
            names[elem]++;
        else
            names.insert(make_pair(elem, 1));
    }
    
    for(auto elem : participant)
    {
        if(names.count(elem)!=0)
        {
            if(names[elem] > 1)
                names[elem]--;
            else
                names.erase(elem);
        }
        else
            return elem;
    }
}