/*
	[����] 16398 �༺ ����
		���� ��ó : https://www.acmicpc.net/problem/16398
		Ǯ�� ���� : 2020.07.02

	[Ǯ�� ���] : �ּ� ���� Ʈ�� (���� �˰���)
*/

#include <iostream>
#include <vector>

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	int N;
	std::cin >> N;
	
	std::vector<std::vector<std::pair<int, int>>> graph (N,std::vector<std::pair<int,int>>(N));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int temp;
			std::cin >> temp;
			graph[i][j] = { temp,j };
		}
	}

	std::cout << "test";
	return 0;
}