#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

// https://programmers.co.kr/learn/courses/30/lessons/17680?language=cpp

int solution(int cacheSize, vector<string> cities) {

	list<string> cache;
	int time = 0;

	if (cacheSize == 0)
		return cities.size() * 5;

	for (int i = 0; i < cities.size(); i++) {
		transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);

		auto cacheIdx = find(cache.begin(), cache.end(), cities[i]);
		if (cacheIdx == cache.end()) {
			// miss
			if (cache.size() >= cacheSize) {
				cache.pop_front();
			}
			cache.push_back(cities[i]);
			time += 5;
		}
		else {
			// hit
			cache.remove(cities[i]);
			cache.push_back(cities[i]);
			time += 1;
		}
	}
	return time;
}