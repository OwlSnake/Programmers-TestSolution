#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 2020.04.16
// https://programmers.co.kr/learn/courses/30/lessons/42889

// pair 비교 함수 정의
bool compare(const pair<int, float>& p1, const pair<int, float>& p2) {
	if (p1.second == p2.second)
		return p1.first < p2.first;
	return p1.second > p2.second;
}

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	vector<pair<int, float>> fail(N);
	// stage 번호 - 1과 실패율 저장

	int playerLeft = stages.size();;

	// 초기화
	for (int i = 0; i < N; i++) {
		fail[i].first = i + 1;
		fail[i].second = 0;
	}

	// stage별 실패 횟수 계산
	for (int i = 0; i < stages.size(); i++) {
		if (stages[i] == N + 1)
			continue;
		fail[stages[i] - 1].second++;
	}

	// 실패율 계산(0으로 나누기 주의!)
	for (int i = 0; i < N; i++) {
		int faliedPlayer = fail[i].second;
		fail[i].second /= playerLeft;
		playerLeft -= faliedPlayer;
		if (playerLeft == 0)
			break;
	}

	// 정렬
	sort(fail.begin(), fail.end(), compare);

	for (int i = 0; i < N; i++) {
		answer.push_back(fail[i].first);
	}

	return answer;
}