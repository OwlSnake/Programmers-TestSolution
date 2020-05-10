#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool dfs(string from, vector<vector<string>> &tickets,
	vector<bool> &used, vector<string> &answer, int cnt) {
	answer.push_back(from);
	for (int i = 0; i < tickets.size(); i++)
	{
		if (used[i])
			continue;

		if (from == tickets[i][0]) {
			used[i] = true;
			bool found;
			found = dfs(tickets[i][1], tickets, used, answer, cnt + 1);
			if (found)
				return true;
			used[i] = false;
		}
	}
	if (cnt == tickets.size())
		return true;
	answer.pop_back();
	return false;
}

vector<string> solution(vector<vector<string>> tickets) {
	vector<string> answer;
	vector<bool> used(tickets.size(), false);

	sort(tickets.begin(), tickets.end());
	dfs("ICN", tickets, used, answer, 0);

	cout << endl;
	return answer;
}

void main() {
	//solution({ {"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"} });
	cout << endl;
	solution({ {"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL", "SFO"} });
}