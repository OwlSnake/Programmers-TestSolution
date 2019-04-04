//https://programmers.co.kr/learn/courses/30/lessons/43165

#include <string>
#include <vector>

using namespace std;

int getSolutionCount(int num, int target, vector<int> arr){
    if(arr.size() == 1){
        // 마지막에 남은 수가 target이면 1 반환
        return (num+arr[0] == target || num-arr[0] == target) ? 1 : 0;
    }
    else{
        // 맨 뒤의 수의 부호가 +, -일 때 가능한 해의 갯수를 구한다
        vector<int> subArr = vector<int>(arr.begin()+1, arr.end());
        return  getSolutionCount(num+arr[0], target, subArr) + getSolutionCount(num-arr[0], target, subArr);
    }
}

int solution(vector<int> numbers, int target) {
    return getSolutionCount(0, target, numbers);
}