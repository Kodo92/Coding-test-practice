/*
	[프로] 야근 지수
		문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/12927
*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
	priority_queue<int> queue(works.begin(), works.end());
	for (int i = 0; i < n && !queue.empty(); i++)
	{
		auto top = queue.top();
		queue.pop();
		top -= 1;
		if(top != 0)
			queue.push(top);
	}

	long long answer = 0;
	while (!queue.empty())
	{
		answer += (long long)queue.top() * (long long)queue.top();
		queue.pop();
	}
	return answer;
}

int main()
{


	return 0;
}