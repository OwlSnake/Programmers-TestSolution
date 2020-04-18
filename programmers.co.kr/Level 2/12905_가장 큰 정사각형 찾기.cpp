#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 2020.04.18
// https://programmers.co.kr/learn/courses/30/lessons/12905

int solution(vector<vector<int>> board)
{
	int answer = 0;
	// 맨 위와 왼쪽에 0으로 이루어진 행과 열을 넣는다
	vector<int> padding;
	for (int i = 0; i < board[0].size(); i++)
		padding.push_back(0);
	board.insert(board.begin(), padding);

	for (int i = 0; i < board.size(); i++) {
		board[i].insert(board[i].begin(), 0);
	}

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[0].size(); j++)
		{
			if (board[i][j] == 0)
				continue;

			int& up = board[i - 1][j];
			int& left = board[i][j - 1];
			int& upleft = board[i - 1][j - 1];

			board[i][j] = min(up, min(left, upleft)) + 1;

			answer = max(answer, board[i][j]);
		}
	}
	return answer * answer;
}