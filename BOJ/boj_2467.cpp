/*
	[백준 2467] 용액
		출처 : https://www.acmicpc.net/problem/2467
		풀이일 : 2022.03.21
		구분 : 투포인터
*/

#include <iostream>
#include <vector>
#include <algorithm>

// 오름차순으로 정렬된 vec를 투 포인터 방식으로 점검해 합이 제일 작은 두 수를 반환한다.
// 이때 pair.first < pair.second이다.
std::pair<int,int> search(const std::vector<int>& vec) {
	int min = 2147483647;
	int left = 0, right = vec.size() - 1;
	std::pair<int, int> answer;
	while (left != right) {
		int sum = vec[left] + vec[right];
		if (min > abs(sum)) {
			min = abs(sum);
			answer.first = vec[left];
			answer.second = vec[right];
		}

		if (sum < 0) {
			left++;
		}
		else {
			right--;
		}
	}
	return answer;
}

int main() {

	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	int N;
	std::cin >> N;

	std::vector<int> vec(N);
	for (size_t i = 0; i < N; i++)
		std::cin >> vec[i];
	
	std::pair<int, int> retval = search(vec);

	std::cout << retval.first << ' ' << retval.second;
}