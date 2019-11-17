#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Meeting {
	int begin, end;
};

bool CompareEndTime(Meeting a, Meeting b) {
	if (a.end == b.end)
		return a.begin < b.begin;
	return a.end < b.end;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int N, lastMeetEnd = 0, answer = 0;
	cin >> N;
	vector<Meeting> meeting(N);
	for (int i = 0; i < N; i++)
		cin >> meeting[i].begin >> meeting[i].end;
	
	sort(meeting.begin(), meeting.end(), CompareEndTime);

	for (int i = 0; i < N; i++)
	{
		if (meeting[i].begin >= lastMeetEnd) {
			lastMeetEnd = meeting[i].end;
			answer++;
		}
	}

	cout << answer;
	
	return 0;
}