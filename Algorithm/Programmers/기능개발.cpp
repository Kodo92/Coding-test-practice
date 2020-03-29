#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// 내 버전
/*

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	map<int, int> Queue;
	int Time = 0, remainingTime = 0;
	for (int i = 0; i < progresses.size(); i++)
	{
		remainingTime = (100 - progresses[i]);
		Time = remainingTime / speeds[i];
		if (remainingTime > (Time*speeds[i]))
			Time++;
		Queue.insert(make_pair(i, Time));
	}
	int completeTime = 0, doneCount =0;
	while (Queue.size())
	{
		doneCount = 0;
		completeTime = Queue.begin()->second;
		for (auto& i : Queue)
		{
			if (Queue.begin()->second > completeTime)
				break;
				doneCount++;
				Queue.erase(Queue.begin());
		}
		answer.push_back(doneCount);
	}
	return answer;
}

*/

// 베스트
/*
vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;

	int day;
	int max_day = 0;
	for (int i = 0; i < progresses.size(); ++i)
	{
		day = (99 - progresses[i]) / speeds[i] + 1;

		if (answer.empty() || max_day < day)
			answer.push_back(1);
		else
			++answer.back();

		if (max_day < day)
			max_day = day;
	}

	return answer;
}
*/
int main()
{
	vector<int> progresses{ 93,30,55, 99 };
	vector<int> speeds{ 1,30,5, 100 };
	vector<int> answer = solution(progresses, speeds);
	for (auto& i : answer)
		cout << i << ' ';
	return 0;
}