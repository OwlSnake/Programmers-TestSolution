#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> visited;
vector <vector<int>> com;
int netCount = 1;

void dfs(int pc) {
	visited[pc] = netCount;
	cout << "visited " << pc << endl;

	for (int i = 0; i < com.size(); i++) {
		if (visited[i])
			continue;

		if (com[pc][i]) 
			dfs(i);
	}
}

int solution(int n, vector<vector<int>> computers) {
	visited = vector<int>(n, 0);
	com = computers;

	for (int r = 0; r < n; r++)
	{
		if (visited[r] == 0) {
			dfs(r);
			cout << "new network found" << endl;
			netCount++;
		}
	}
	
	return netCount - 1;
}

void main() {
	cout << solution(4, { {1,0,0,1},{0,1,1,1},{0,1,1,0},{1,1,0,1} }) << endl;
	//cout << solution(3, { {1,1,0},{1,1,1},{0,1,1} }) << endl;
}