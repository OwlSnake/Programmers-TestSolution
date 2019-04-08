https://programmers.co.kr/learn/courses/30/lessons/12913

#include <vector>
#include <algorithm>

using namespace std;

// arr에서 가장 큰 수를 return
int maxInArr(vector<int> arr, int exep)
{
    int result = 0;
    for(int i=0; i<arr.size(); i++)
    {
        if(i==exep) continue;
        result = max(result, arr[i]);
    }
    return result;
}

int solution(vector<vector<int> > land)
{
    int answer = 0;
    // 맨 아래칸부터 각 칸에, 해당 칸부터 내려갔을 시 얻을 수 있는 최대 점수를 기록한다
    for(int row = land.size()-2; row>=0; row--)
        for(int col=0; col<4; col++)
            land[row][col] += maxInArr(land[row+1], col);
    
    return *max_element(land[0].begin(), land[0].end());
}