// https://programmers.co.kr/learn/courses/30/lessons/1845

#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> nums)
{
    unordered_map<int, int> pokeMap;
    // 폰켓몬의 종류를 센다. unordered_map을 사용
    for(int num : nums)
        pokeMap[num]++;
    
	return min(pokeMap.size(), nums.size()/2);
}