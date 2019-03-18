//https://programmers.co.kr/learn/courses/30/lessons/12915

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    for(int i=0; i<strings.size()-1; i++)
    {
        for(int j=0; j<strings.size()-i-1; j++)
        {
            if(strings[j][n]==strings[j+1][n])
                if(strings[j]>strings[j+1])
                    swap(strings[j], strings[j+1]);
            
            if(strings[j][n]>strings[j+1][n])
                swap(strings[j], strings[j+1]);
        }
    }
    return strings;
}