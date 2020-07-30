/*
	[백준] 3430 용이 산다
		문제 출처 : https://www.acmicpc.net/problem/3430

	[실패 과정]
		1. rain.front 호수에 물이 차있는지만 탐색
			-> rain을 순회하면서 먹을 수 있는 물 먹음
		2. 시간초과
			-> deque 순회와 erase가 시간을 많이 잡아먹음
*/

#include <iostream>
#include <deque>

void rain()
{
	int N, M;
	std::cin >> N >> M;
	
	std::deque<int> sequence (M);
	std::deque<int> rain;
	std::deque<bool> lakes(N,true);
	std::deque<int> answer;
	for (int i = 0; i < M; i++)
	{
		std::cin >> sequence[i];
		if (sequence[i] != 0)
			rain.push_back(sequence[i]-1);
	}

	bool isCorrect = true;
	for (const auto& val : sequence)
	{
		if (val == 0)
		{
			if (!rain.empty())
			{
				bool isFind = false;
				for (int i = 0; i < rain.size(); i++)
				{
					if (lakes[rain[i]])
					{
						isFind = true;
						lakes[rain[i]] = false;
						answer.push_back(rain[i]);
						rain.erase(rain.begin()+i);
						break;
					}
				}
				if(!isFind)
					answer.push_back(-1);
			}
			else
				answer.push_back(-1);

		}
		else
		{
			if (!lakes[val-1])
			{
				lakes[val-1] = true;
			}
			else
			{
				isCorrect = false;
				break;
			}
		}
	}
	if (!rain.empty())
		isCorrect = false;
	if (!isCorrect)
	{
		std::cout << "NO" << '\n';
		return;
	}
	std::cout << "YES" << '\n';
	for (const auto& val : answer)
		std::cout << (val+1) << ' ';
	std::cout << '\n';
}

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	int T;
	std::cin >> T;
	for (int i = 0; i < T; i++)
		rain();

	return 0;
}