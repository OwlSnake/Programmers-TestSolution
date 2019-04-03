//https://programmers.co.kr/learn/courses/30/lessons/42841

#include <string>
#include <vector>

using namespace std;

// 문자열과 세 자리 숫자로 Strike와 Ball의 갯수를 반환하는 함수
int getStrikes(string str, int num){
    int strikes = 0;
    string numStr = to_string(num);
    
    for(int i=0; i<3; i++)
        if(numStr[i]==str[i]) strikes++;
    return strikes;
}
int getBalls(string str, int num){
    int balls = 0;
    string numStr = to_string(num);
    
    if(numStr[0]==str[1] || numStr[0]==str[2]) balls++;
    if(numStr[1]==str[0] || numStr[1]==str[2]) balls++;
    if(numStr[2]==str[0] || numStr[2]==str[1]) balls++;
    return balls;
}

int solution(vector<vector<int>> baseball) {
    int answer = 0;
    bool isNumValid; //123~987중 이 숫자가 조건을 만족하는지 여부
    
    for(int num=123; num<=987; num++){
        string str = to_string(num);
        isNumValid = true;
        
        // 야구 게임의 3자리 숫자에는 중복이나 0이 있을 수 없음
        if(str[0]=='0' || str[1]=='0' || str[2] =='0') continue;
        if(str[0]==str[1] || str[1]==str[2] || str[2]==str[0]) continue;
        
        // 테스트 결과를 가져와 조건을 만족하는지 확인
        for(vector<int> test : baseball){
            if(getStrikes(str, test[0]) != test[1]){
                isNumValid = false;
                break;
            }
            if(getBalls(str, test[0]) != test[2]){
                isNumValid = false;
                break;
            }
        }

        // 조건을 만족하면 answer++
        if(isNumValid)
            answer++;
    }
    return answer;
}