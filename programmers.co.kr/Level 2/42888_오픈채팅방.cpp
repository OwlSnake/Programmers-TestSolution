#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	unordered_map<string, string> username;

	string cmd, id, name;
	for (string s : record) {
		stringstream ss(s);
		ss >> cmd;
		ss >> id;
		if (cmd != "Leave") {
			ss >> name;
			username[id] = name;
		}
	}

	for (string s : record) {
		stringstream ss(s);
		ss >> cmd;
		ss >> id;

		if (cmd == "Enter") {
			name = username[id];
			string temp = name + "���� ���Խ��ϴ�.";
			answer.push_back(temp);
		}
		if (cmd == "Leave") {
			name = username[id];
			string temp = name + "���� �������ϴ�.";
			answer.push_back(temp);
		}
	}

	return answer;
}