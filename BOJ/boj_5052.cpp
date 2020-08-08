/*
	[백준] 5052 전화번호 목록
		문제 출처 : https://www.acmicpc.net/problem/5052

	[풀이 방법] 정렬
		1. input을 문자열 형태로 받고 배열에 저장
		2. 정렬 후 i와 i+1을 비교 (i+1은 substr이용해서 i의 길이만큼 문자열 추출)
		3. 같은 것이 나오면 NO, 아니면 YES
		=> 120ms

	[실패 과정]
		1. 문자열로 0부터 comapred size까지 비교하는 반복문을 총 N*N번 반복 : 시간초과
		2. 입력 순서대로 문자열 분해해서 N*N (이전 짭 TRIE 만든 것 처럼) : 시간초과

	[풀이 일자] 2020.08.08

	None -> 120ms
	cin.tie(0) -> 116ms (-4ms)
	sync_with_stdio(false) -> 60ms (-60ms)
	tie + sync -> 56ms
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	int T;
	std::cin >> T;
	while (T--)
	{
		int N;
		std::cin >> N;
		std::vector<std::string> dictionary(N);

		for (int i = 0; i < N; i++)
			std::cin >> dictionary[i];

		std::sort(dictionary.begin(), dictionary.end());

		bool isFind = false;
		for (int i = 0; i < N - 1; i++)
		{
			if (dictionary[i] == dictionary[i + 1].substr(0, dictionary[i].size()))
			{
				isFind = true;
				break;
			}
		}

		if (isFind)
			std::cout << "NO" << '\n';
		else
			std::cout << "YES" << '\n';
	}
}