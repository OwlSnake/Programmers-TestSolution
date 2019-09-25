//https://programmers.co.kr/learn/courses/30/lessons/42583

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int len, int maxWeight, vector<int> trucks) {
    int time = 0, curWeight = 0;
    queue<int> bridge;
    // Initalize bridge queue with 0's
    for(int i=0; i<len; i++)
        bridge.push(0);

    while(true)
    {
        if(trucks.empty()) // Last truck is on bridge
            return time + len;

        curWeight -= bridge.front();
        bridge.pop();
        
        if(trucks.front() + curWeight <= maxWeight)
        {
            bridge.push(trucks.front());
            curWeight += bridge.back();
            trucks.erase(trucks.begin());
        }
        else
            bridge.push(0);
        
        time += 1;
    }
}