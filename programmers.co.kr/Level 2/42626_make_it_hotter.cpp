//https://programmers.co.kr/learn/courses/30/lessons/42626

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int elem : scoville)
        pq.push(elem);
    
    while(pq.size() > 1)
    {
        int temp = 0;
        temp+=pq.top();
        pq.pop();
        temp+=pq.top()*2;
        pq.pop();
        pq.push(temp);    
        answer++;
        
        if(pq.top() >= K)
            return answer;
    }
    return -1;
}