#include <iostream>
#include <vector>
#include <algorithm>

/*
	풀이 방법:
		- N개의 입력값 중 최소값 : left, 최댓값 : right 으로 하고 이분탐색 실행
		- mid 까지 정수의 갯수 합을 구함 : 홀수 (이미 홀수인 정수가 나옴)
*/

std::vector<std::vector<unsigned int>> pile;
int N;

int getCount(const int value)
{
	int count = 0;
	for (const auto i : pile)
	{
		if (i[0] > value) continue;		// min > value : 이 조건 범위에는 value보다 작은 값이 존재하지 않음.
		for (int j = i[0]; j <= value && j <= i[1]; j += i[2], count++);
	}
	return count;
}

int main()
{
	std::cin >> N;

	unsigned int min, max, add;
	unsigned int left = INT_MAX, right = 0;	
	for (int i = 0; i < N; i++)
	{
		std::cin >> min >> max >> add;
		pile.push_back({ min,max,add });
		left = std::min(left, min);
		right = std::max(right, max);
	}

	unsigned int mid = 0;	// left : 1 , right : INT_MAX의 경우 left+right = int overflow
	int answer = -1;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (getCount(mid) % 2 == 0)
			left = mid + 1;
		else
		{
			right = mid - 1;
			answer = mid;
		}
	}

	if (answer == -1)
		std::cout << "NOTHING";
	else
		std::cout << answer<<' '<<(getCount(answer) - getCount(answer - 1));

	return 0;
}

/*
3
1 10 1
1 5 1
6 10 1
answer : NOTHING
*/