//https://programmers.co.kr/learn/courses/30/lessons/12901

#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    string dayNames[7] = { "FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
    int daysInMonth[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days;
    
    for(int i=0; i < a-1; i++)
        days += daysInMonth[i];
    
    days += b;
    
    answer = dayNames[(days-1)%7];
    
    return answer;
}