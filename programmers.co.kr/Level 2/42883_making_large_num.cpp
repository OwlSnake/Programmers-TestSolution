//https://programmers.co.kr/learn/courses/30/lessons/42883

#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    int i = 0;
    while(k > 0){
        if(i==number.size()-2){
            if(number[i]<number[i+1])
                number.erase(i, 1);
            else
                number.erase(i+1, 1);
            k--;
            i=0;
        }
        else if(number[i]<number[i+1]){
            number.erase(i, 1);
            k--;
            i=0;
        }
        else
            i++;
    }
    return number;
}