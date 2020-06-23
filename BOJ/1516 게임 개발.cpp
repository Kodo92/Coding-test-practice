/*
	[백준] 1516. 게임 개발
	문제 출처 : https://www.acmicpc.net/problem/1516
	풀이 : 2020.06.19
	비고 : sloved.
*/

/*
	[풀이 방법] - BFS 알고리즘을 이용
	1. i번째 노드를 진입노드로 갖는 노드들을 vector로 관리
		ex ) 1번 노드를 진입노드로 갖는 노드들 2,3,4,6		=>		vector[i]. {2, 3, 4, 6}
	2. queue에 진입노드가 없는 노드들 삽입 (노드별 refCount로 진입노드 카운팅)
	3. answer[i]에 value (time)를 저장	=> 진입노드 시간 (answer[i]) + 현재노드 시간
	4. 현재 노드의 값이 새로 계산한 값 보다 작은경우 answer[i] = 새로 계산한 값
		- 먼저 지어져야 하는 건물이 모두 건설되어야 i번째 건물을 건설할 수 있다. 
		- 3번 건물을 짓기 위해 1,2번 건물을 지어야한다면, 1번 완성시간 10초 / 2번 완성시간 20초 라면 3번 건물은 20초부터 건설할 수 있다.
*/

#include <iostream>
#include <vector>
#include <queue>

struct pathData
{
	int value = 0;
	std::vector<int> paths;
	int refCount = 0;
};

std::vector<std::pair<int, pathData>> list;
std::vector<int> answer;

void bfs()
{
	std::queue<int> queue;

	for (int i = 1; i < list.size(); i++)
	{
		if (list[i].second.refCount == 0)
		{
			queue.push(i);
			answer[i] = list[i].second.value;
		}
	}

	while (!queue.empty())
	{
		auto front = queue.front();
		queue.pop();
		int value = answer[front];
		
		for (const auto i : list[front].second.paths)
		{
			int newValue = value + list[i].second.value;
			if (answer[i] < newValue)
			{
				queue.push(i);
				answer[i] = newValue;
					
			}
		}
	}
}

int main()
{
	// input의 노드 위치가 1부터 시작이므로 N+1 해줌.
	int N;
	std::cin >> N;
	list.resize(N + 1);

	for (int i = 1; i <= N; i++)
	{
		int input;
		std::cin >> input;
		
		list[i].second.value = input;
		while (std::cin >> input)
		{
			if (input == -1)
				break;
			list[input].second.paths.push_back(i);
			list[i].second.refCount++;
		}
	}

	answer.resize(N + 1);
	bfs();

	for (int i=1;i<=N;i++)
		std::cout << answer[i] << '\n';
	return 0;
}