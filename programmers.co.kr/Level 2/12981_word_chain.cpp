// https://programmers.co.kr/learn/courses/30/lessons/12981

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    answer.push_back(0);
    answer.push_back(0);
    
    // 첫 단어는 루프에서 제외
    unordered_map<string, int> usedWords;    
    usedWords[words[0]]++;

    for(int i=1; i<words.size(); i++){
        // 앞 단어와 이어지지 않음 or 단어 중복
        if(words[i-1].back() != words[i].front() || usedWords.count(words[i]) > 0){
            answer[0] = i%n+1; // 틀린 사람
            answer[1] = i/n+1; // 틀린 차례
            break;
        }
        usedWords[words[i]]++;
    }
    return answer;
}