//https://programmers.co.kr/learn/courses/30/lessons/42885

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int frontIndex = 0, backIndex = people.size()-1;
    // 두 인덱스의 사이에 있는 숫자가 아직 대피하지 못한 사람의 무게를 나타냄

    sort(people.begin(), people.end(), less<int>());
    
    while(frontIndex <= backIndex){
        // 제일 가벼운 사람과 무거운 사람의 무게를 확인
        // 무게 제한을 초과할 시 무거운 사람만 탈 수 있다 
        if(people[frontIndex]+people[backIndex] <= limit)
            frontIndex++;
        
        backIndex--;
        answer++;
    }
    return answer;
}