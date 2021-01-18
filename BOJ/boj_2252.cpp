/*
	[백준] 2252 줄 세우기
		문제 출처 : https://www.acmicpc.net/problem/2252

	[풀이 방법] 위상정렬 (BFS)
		1. A는 B의 앞에 와야하는 조건은 B의 진입 차수가 추가되는 것 이다.
		2. 진입 차수가 0인 것들을 큐에 넣는다.
		3. 큐에서 인덱스를 뽑아 그 인덱스의 출력 차수를 제거해준다. (목적지의 진입 차수 --)

	[실패 과정]

	[풀이 일자] 2020.07.27
*/

#include <iostream>
#include <vector>
#include <queue>

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	int N, M;
	std::cin >> N >> M;

	std::vector<int> inDegreeCount(N, 0);
	std::vector<std::vector<int>> paths(N, std::vector<int>());

	for (int i = 0; i < M; i++)
	{
		int A, B;
		std::cin >> A >> B;
		inDegreeCount[--B]++;
		paths[--A].push_back(B);
	}

	std::queue<int> queue;
	for (int i = 0; i < N; i++)
	{
		if (!inDegreeCount[i])
			queue.push(i);
	}
	
	while (!queue.empty())
	{
		int nowIndex = queue.front();
		std::cout << (nowIndex+1) << ' ';
		queue.pop();

		for (const auto i : paths[nowIndex])
		{
			inDegreeCount[i]--;
			if (!inDegreeCount[i])
				queue.push(i);
		}
	}

	return 0;
}