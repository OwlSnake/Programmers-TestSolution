//https://programmers.co.kr/learn/courses/30/lessons/12899

#include <string>
#include <vector>
#include <queue>

using namespace std;

string solution(int n) {
    string answer = "";
    vector<int> stack;
    while(n > 3)
    {
        if(n%3 == 0)
        {
            stack.push_back(3);
            n = (n/3) - 1;
        }
        else
        {
            stack.push_back(n%3);
            n = n/3;
        }
    }
    stack.push_back(n);

    // Convers 3 to 4
    while(!stack.empty())
    {
        if(stack.back() == 3)
            answer += "4";
        else
            answer += to_string(stack.back());
        stack.pop_back();
    }
    
    return answer;
}