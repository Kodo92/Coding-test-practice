#include<iostream>
#include <algorithm>

int min;

void dfs(const int N, const int number, const int count, const int value)
{
	if (count >= min || count >= 8)	return;	// count가 9이면 -1 출력 && count가 최솟값이 아니라면 탐색하지 않음. (문제에서 요구하는 것은 최솟값임)
	if (value == number)
		min = std::min(min, count + 1);

	int tempNumber = 0;
	for (int i = 0; i + count < 8; i++)
	{
		tempNumber = tempNumber * 10 + N;
		dfs(N, number, count + (i + 1), value + tempNumber);
		dfs(N, number, count + (i + 1), value - tempNumber);
		dfs(N, number, count + (i + 1), value * tempNumber);
		dfs(N, number, count + (i + 1), value / tempNumber);
	}
}

int solution(int N, int number) {
	min = 9;			// 최솟값이 8보다 크면 -1 리턴

	dfs(N, number, 0, 0);

	return (min == 9) ? -1 : min;
}

int main()
{
	std::cout << solution(5, 23);
}

/*
1. A+B
2. A-B
3. A*B	(A != 0)
4. A/B	(A != 0)


testcase
5 12 : 4
2 11 : 3


*/