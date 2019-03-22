//https://programmers.co.kr/learn/courses/30/lessons/12935

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    int min;
    if(arr.size()==1) return {-1};
    
    min = *min_element(arr.begin(), arr.end());
    arr.erase(find(arr.begin(), arr.end(), min));
    return arr;
}