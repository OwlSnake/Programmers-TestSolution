// https://programmers.co.kr/learn/courses/30/lessons/12951
#include <string>

using namespace std;

string solution(string s) {
    string answer = "";
    bool isFirst = true;
    for(char c : s){
        if(isFirst && c!=' '){
            c = toupper(c);
            isFirst = false;
        }
        else if(c==' ')
            isFirst = true;
        else
            c = tolower(c);

        answer += c;
    }
    return answer;
}