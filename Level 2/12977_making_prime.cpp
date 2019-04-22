// https://programmers.co.kr/learn/courses/30/lessons/12977

#include <vector>
#include <algorithm>

using namespace std;

bool isPrime(int x)
{
    if(x<=3) return true;
    if(x%2==0 || x%3==0) return false;
    for(int i=5; i*i<=x; i+=6)
        if(x%i==0 || x%(i+2)==0)
            return false;
    return true;
}

int solution(vector<int> nums) {
    int answer = 0, sum = 0;
    
    // 1이 3개, 나머지는 0으로 채운다
    vector<int> combinationMaker;
    for(int i=0; i<3; i++)
        combinationMaker.push_back(1);
    while(combinationMaker.size()<nums.size())
        combinationMaker.push_back(0);

    sort(combinationMaker.begin(), combinationMaker.end());
    
    // nums에서 3개를 뽑아 Combination을 만들고 합을 구한다
    do{
        sum = 0;
        for(int i=0; i<nums.size(); i++)
            if(combinationMaker[i]==1)
                sum += nums[i];
            
        if(isPrime(sum))
            answer++;
        
    }while(next_permutation(combinationMaker.begin(), combinationMaker.end()));

    return answer;
}