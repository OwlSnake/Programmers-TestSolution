#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

#include <iostream>

using namespace std;

int timeToSec(const string time) {

	int h = stoi(time.substr(0, 2));
	int m = stoi(time.substr(3, 2));
	int s = stoi(time.substr(6, 2));
	int ms = stoi(time.substr(9, 3));

	m += h * 60;
	s += m * 60;
	ms += s * 1000;

	return ms;
}

int durationToSec(string duration) {
	duration.erase(duration.end() - 1);
	float time = stof(duration);
	int sec = time * 1000;
	return sec;
}

int solution(vector<string> lines) {
	int maxCapacity = 0;

	vector<pair<int, int>> records;

	for (string line : lines) {
		stringstream ss(line);

		string date, time, duration;
		ss >> date >> time >> duration;

		int endTime = timeToSec(time);
		int beginTime = endTime - durationToSec(duration) + 1;

		records.push_back(make_pair(beginTime, endTime));
	}

	for (int i = 0; i < records.size(); i++) {
		int cap = 1;
		int endTime = records[i].second;

		for (int j = i + 1; j < records.size(); j++) {
			if (records[j].first < endTime + 1000) {
				cap++;
			}
		}
		maxCapacity = max(cap, maxCapacity);
	}

	return maxCapacity;
}
void main() {
	cout << solution({ "2016-09-15 20:59:57.421 0.351s", "2016-09-15 20:59:58.233 1.181s", "2016-09-15 20:59:58.299 0.8s", "2016-09-15 20:59:58.688 1.041s", "2016-09-15 20:59:59.591 1.412s", "2016-09-15 21:00:00.464 1.466s", "2016-09-15 21:00:00.741 1.581s", "2016-09-15 21:00:00.748 2.31s", "2016-09-15 21:00:00.966 0.381s", "2016-09-15 21:00:02.066 2.62s" });
	cout << endl;
	//cout << solution({ "2016-09-15 00:00:00.000 3s" });
	cout << endl;
}