//https://programmers.co.kr/learn/courses/30/lessons/12930

#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int gap = 'A' - 'a';
    bool isCapital = true;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]==' ')
        {
            isCapital = true;
            continue;
        }
        if(isCapital && 'a'<=s[i] && s[i]<='z')
            s[i] += gap;
        else if(!isCapital && 'A'<=s[i] && s[i]<='Z')
            s[i] -= gap;
        isCapital = !isCapital;
    }
    return s;
}