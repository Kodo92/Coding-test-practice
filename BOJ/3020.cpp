/*
	[BOJ] 3020 개똥벌레
		문제 출처 : https://www.acmicpc.net/problem/3020

	[문제 풀이] : 이분 탐색 (upper_bound, lower_bound)
		1. 종유석과 석순의 높이를 각각 벡터에 저장한 후 정렬한다.
		2. 높이 1부터 H까지 루프를 돌면서 통과하는 장애물 갯수를 탐색한다.
			- map을 사용해 장애물 갯수 별 count를 관리는 것과 단순 변수에 최소값만을 저장해 cnt++하는 것은 12ms의 차이가 난다. (map의 input시마다 정렬하는 부분 때문이라고 판단)
		2-1. 종유석 (up) : 높이가 (H - i) 보다 큰 것들을 제외한 나머지가 통과되는 장애물 갯수이다.	-> upper_bound
		2-2. 석순 (down) : 높이가 i보다 작은것들을 제외한 나머지가 통과되는 장애물 갯수이다.	-> lower_bound.			

	[과정]
		1. 완전 탐색으로 높이가 1부터 H까지 조건을 체크하는 것은 시간초과 발생. : 최대 1천억번 루프
			 - 탐색했을 때 장애물의 갯수가 최솟값보다 크면 루프 탈출 : 시간 초과

	[풀이 일자] 2020.07.09.
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	int N, H;
	std::cin >> N >> H;

	std::vector<int> up;
	std::vector<int> down;

	for (int i = 0; i < N; i++)
	{
		int temp;
		std::cin >> temp;
		if (i % 2 == 0)
			up.push_back(temp);
		else
			down.push_back(temp);
	}

	std::sort(up.begin(), up.end());
	std::sort(down.begin(), down.end());

	int answer = 2147483647;
	int cnt = 1;
	for (int i = 1; i <= H; i++)
	{
		// 석순
		int count = down.size() - (std::lower_bound(down.begin(), down.end(), i) - down.begin());
		// 종유석
		count += up.size() - (std::upper_bound(up.begin(), up.end(), (H - i)) - up.begin());
		if (answer == count)
			cnt++;
		if (answer > count)
		{
			answer = count;
			cnt = 1;
		}
	}

	std::cout << answer << ' ' << cnt;
	return 0;
}