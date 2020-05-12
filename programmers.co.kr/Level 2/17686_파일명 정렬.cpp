#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct fileName {
	string head;
	int number;
	string tail;
	string origName;
};

fileName parseFile(string name) {
	int numBegin = 0, numEnd = 0;
	for (int i = 0; i < name.length(); i++) {
		if (name[i] >= '0' && name[i] <= '9') {
			if (numBegin == 0) {
				numBegin = i;
			}
		}
		else {
			if (numBegin != 0 && numEnd == 0) {
				numEnd = i;
			}
		}
	}

	string head = name.substr(0, numBegin);
	int number = stoi(name.substr(numBegin, numEnd - numBegin));
	string tail = name.substr(numEnd);
	string origName = name;

	for (char &c : head) {
		c = tolower(c);
	}

	return fileName{ head, number, tail, origName };
}

bool compareFile(fileName a, fileName b) {

	if (a.head != b.head)
		return a.head < b.head;

	return a.number < b.number;
}

vector<string> solution(vector<string> files) {
	vector<fileName> f;
	vector<string> answer;

	for (string file : files) {
		f.push_back(parseFile(file));
	}

	stable_sort(f.begin(), f.end(), compareFile);

	for (fileName file : f) {
		answer.push_back(file.origName);
	}

	return answer;
}

void main() {

	cout << ("Abcd" > "abcd") << endl;

	solution({ "img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG" });
	solution({ "F - 5 Freedom Fighter", "B - 50 Superfortress", "A - 10 Thunderbolt II", "F - 14 Tomcat"});
}