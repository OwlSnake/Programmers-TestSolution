//https://programmers.co.kr/learn/courses/30/lessons/12926

#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    int a = 'a', z = 'z', A = 'A', Z = 'Z';
    int range = z-a+1;
    
    for(int i=0; i<s.size(); i++)
    {
        if(a<=s[i] && s[i]<=z)
            answer += (s[i]+n <= z) ? s[i]+n : (s[i]+n)-range;
        else if(A<=s[i] && s[i]<=Z)
            answer += (s[i]+n <= Z) ? s[i]+n : (s[i]+n)-range;
        else
            answer += ' ';
    }
    return answer;
}