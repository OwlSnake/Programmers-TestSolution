#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int wordDiff(const string &a, const string &b) {
	int diff = 0;
	for (int i = 0; i < a.length(); i++)
		if (a[i] != b[i])
			diff++;
	return diff;
}

int solution(string begin, string target, vector<string> words) {

	// 시작 단어 추가
	words.insert(words.begin(), begin);
	const int N = words.size();
	int beginIdx = 0, targetIdx = -1;
	auto targetIter = find(words.begin(), words.end(), target);
	if (targetIter == words.end())
		return 0;
	targetIdx = distance(words.begin(), targetIter);

	// 변환 가능한 단어 그래프
	vector<vector<bool>> changable(N, vector<bool>(N, false));
	for (int i = 0; i < N; i++){
		for (int j = i + 1; j < N; j++){
			if (wordDiff(words[i], words[j]) == 1) {
				changable[i][j] = true;
				changable[j][i] = true;
			}
		}
	}

	// BFS
	queue<int> q;
	vector<int> dist(N, 0);
	vector<bool> visited(N);
	q.push(beginIdx);
	visited[beginIdx] = true;
	while (!q.empty()) {
		int node = q.front();

		cout << "from " << words[node] << endl;
		q.pop();
		for (int i = 0; i < N; i++) {
			if (changable[node][i] && !visited[i]) {
				dist[i] = dist[node] + 1;
				q.push(i);
				visited[i] = true;

				cout << "search to " << words[i] << endl;
			}
		}
	}
	return dist[targetIdx];
}

void main() {

	cout << solution("hit", "cog", { "hot", "dot", "dog", "lot", "log", "cog" });
	cout << endl;
	cout << solution("hit", "cog", { "hot", "dot", "dog", "lot", "log" });
}