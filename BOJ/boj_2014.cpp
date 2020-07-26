/*
	[백준] 2014 소수의 곱
		문제 출처 : https://www.acmicpc.net/problem/2014

	[풀이 방법]	set
		1. 우선순위 큐로 풀어보다가 중복된 값이 들어가서 set을 이용했다.
		2. 계산된 값들에 대해 소수들을 계속 곱해준다.
		3. 정답은 INT 범위 이내이며 값들의 크기는 무한으로 증식하지 않게 조건을 걸어준다.
			- 계산된 값들의 갯수가 N보다 크고 새로 계산한 값이 계산된 값들의 최댓값보다 크면 계산된 값을 버린다. 
				필요한 것은 큰 값이 아니라 계산된 값들 사이에 들어갈 작은 수이다.

	[실패 과정]
		1. 문제를 잘못 이해했었다. 계산한 소수의 곱에다가 소수를 또 곱해줘야했다.
		2. 정답의 범위는 INT였다. 이 처리를 하지 않으니 메모리초과가 나왔다.
		3. 계산한 소수들의 곱의 갯수가 N을 넘고 계산 결과가 곱들의 최댓값보다 크다면 제외해주는 로직을 추가했다. -> 시간초과 문제 해결

	[풀이 일자]	2020.07.26.
*/

#include <iostream>
#include <vector>
#include <set>
#include <climits>
#include <algorithm>

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	int K, N;
	std::cin >> K >> N;

	std::vector<int> decimals(K);
	std::set<int> calculatedNumbers;
	for (int i = 0; i < K; i++)
	{
		std::cin >> decimals[i];
		calculatedNumbers.insert(decimals[i]);
	}
	int count = 1;
	long long answer = 0, maxNumber = decimals.back();
	while (true)
	{
		answer = static_cast<long long>(*(calculatedNumbers.begin()));
		calculatedNumbers.erase(calculatedNumbers.begin());

		if (count == N)
			break;

		for (const auto data : decimals)
		{
			long long multiplicatedResult = answer * data;
			if (multiplicatedResult >= INT_MAX) break;
			if (calculatedNumbers.size() > N && multiplicatedResult > maxNumber) break;
			maxNumber = std::max(maxNumber, multiplicatedResult);
			calculatedNumbers.insert(multiplicatedResult);
		}
		count++;
	}
	std::cout << answer;
	return 0;
}