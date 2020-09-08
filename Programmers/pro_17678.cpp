/*
	[프로] 셔틀버스
		문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/17678
		비고 : 2018 카카오 블라인드 공개채용

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// n : 운행 횟수, t : 운행 간격, m : 최대 탑승 크루 수

string getNextBusTime(string nowTime, int term)
{
	int hour = stoi(nowTime);
	int min = stoi(nowTime.substr(3, 2));
	min += term;
	if (min / 60 > 0)
	{
		hour += min / 60;
		min %= 60;
	}
	string ret;
	if (hour < 10)
		ret += '0';
	ret += to_string(hour) + ':';
	if (min < 10)
		ret += '0';
	ret += to_string(min);

	return ret;
}

string solution(int n, int t, int m, vector<string> timetable) {
	sort(timetable.begin(), timetable.end());

	if (n == 1 && m == 1)
	{
		if (timetable.front() > "09:00")
			return "09:00";
	}

	string busTime = "09:00";
	int loopStartIndex = 0;
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < m; j++, loopStartIndex++)
		{
			if (timetable[loopStartIndex] > busTime)
				break;
		}
		busTime = getNextBusTime(busTime, t);
	}

	// 마지막 버스
	string answer = "";
	if (timetable.size() - loopStartIndex >= m)
	{
		int count = 0;
		for ( count = 0; count < m; count++ ,loopStartIndex++)
		{
			if (timetable[loopStartIndex] > busTime)
				break;
		}

		if (count < m-1)
			answer = busTime;
		else
		{
			if (loopStartIndex == timetable.size())
				loopStartIndex--;
			string tempStr = timetable[loopStartIndex];
			int hour = stoi(tempStr);
			int min = stoi(tempStr.substr(3, 2));
			if (min == 0)
			{
				hour -= 1;
				min = 59;
			}
			else
				min -= 1;
			if (hour < 10)
				answer += '0';
			answer += to_string(hour) + ':';
			if (min < 10)
				answer += '0';
			answer += to_string(min);
		}
	}
	else
		answer = busTime;

	return answer;
}

int main()
{
	solution(2, 10, 2, { "09:10", "09:09", "08:00" });
	//solution(1,1, 1, { "23:59"});
	//solution(10, 60, 45, { "23:59","23:59","23:59","23:59","23:59","23:59","23:59","23:59","23:59","23:59","23:59","23:59","23:59","23:59","23:59","23:59" });
	//solution(1, 10, 3, { "09:10", "09:09", "09:00" });
	return 0;
}