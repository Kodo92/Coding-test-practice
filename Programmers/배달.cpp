#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int solution(int N, vector<vector<int> > road, int K) {
	map<int, std::vector<pair<int, int>>> datas;
	map<int, int> answer;
	priority_queue<pair<int, int>> graph;

	for (const auto& i : road)
		datas[i[0]-1].push_back(make_pair(i[1]-1, i[2]));

	std::vector<int> times(50, 500000);

	times[0] = 0;
	graph.push({ 0,0 });
	answer[0] = 0;


	while (!graph.empty())
	{
		const auto front = graph.top();
		const auto currentTime = -front.first;
		graph.pop();

		for (const auto dest : datas[front.second])
		{
			int newTime = currentTime + dest.second;
			if (newTime < times[dest.first])
			{
				graph.push({ -newTime,dest.first });
				times[dest.first] = newTime;
				if (newTime <= K)
					answer[dest.first] = newTime;
			}
		}
	}

	for (const auto i : answer)
	{
		cout << i.second << ':' << i.first << '/';
	}
	return answer.size();
}

int main()
{

	cout << solution(6, { {1,2,1},{ 2,3,3 },{ 5,2,2 },{ 1,4,2 },{ 5,3,1 },{ 5,4,2 } }, 3);

	return 0;
}