/*
	[백준] 1507 궁금한 민호
	
	[풀이 방법] 플로이드 와샬
		1. 플로이드 와샬 알고리즘을 역순으로 되돌리는 느낌으로 문제를 풀었다.
		2. a -> b에서 a->k->b라면 [a][k] + [k][b] == [a][b]일 것이다. 이 조건이 만족한다면 [a][b] = 0으로 변경해준다.
		3. 문제에서 A->B의 모든 경우가 가능하다고 했다. 이말은 A->B가 최소 거리가 아니라면 불가능한 경우라고 한다.

	[실패 과정]
		1. distance 배열의 값을 0으로 설정해버려서 틀림. -> answer 배열 추가로 생성

	[풀이 일자] 2020.07.31
*/

#include <iostream>
#include <vector>

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	int N;
	std::cin >> N;

	std::vector<std::vector<int>> distance(N, std::vector<int>(N));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			std::cin >> distance[i][j];
	}

	std::vector<std::vector<int>> answer = distance;
	for (int k = 0; k < N; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (i==k||j==k) continue;
				if (distance[i][j] == (distance[i][k] + distance[k][j]))
					answer[i][j] = 0;
				else if(distance[i][j] > distance[i][k] + distance[k][j])
				{
					std::cout << -1;
					return 0;
				}
			}
		}
	}

	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
			sum += answer[i][j];
	}
	std::cout << sum;

	return 0;
}