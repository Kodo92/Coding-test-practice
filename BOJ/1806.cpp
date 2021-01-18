/*
	[백준] 1806 부분합
		문제 출처 : https://www.acmicpc.net/problem/1806

	[풀이 방법] : 투 포인터 (슬라이딩 윈도우)
		1. 시작 인덱스부터 부분합이 S를 만족하는 길이를 찾는다.
		2. 길이를 만족할 경우 시작 인덱스를 길이에서 제외한다.
		3. 1번을 반복한다.

	[과정]
		1. index 0부터 N-1까지 모든 경우 체크 -> 시간 초과 
			- 완전 탐색 : X
		2. sequence[0] 부분 체크 수정
		3. N개 모두 사용하는 경우 체크 (10 10 1 1 1 1 1 1 1 1 1 1) output : 10
	[풀이 일자] : 2020.07.09.
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	int N, S;
	std::cin >> N >> S;

	std::vector<int> sequence(N);
	for (int i = 0; i < N; i++)
		std::cin >> sequence[i];

	int answer = 100000;
	int startIndex = 0, endIndex = 1, count = 1;
	int sum = sequence[0];
	while (endIndex <= N)
	{
		if (sum < S)
		{
			sum += sequence[endIndex++];
			count++;
		}
		else
		{
			answer = std::min(answer, count);
			sum -= sequence[startIndex++];
			count--;
		}
	}
	std::cout << ((answer != 100000) ? answer : 0);
	return 0;
}