/*
	[���� 2467] ���
		��ó : https://www.acmicpc.net/problem/2467
		Ǯ���� : 2022.03.21
		���� : ��������
*/

#include <iostream>
#include <vector>
#include <algorithm>

// ������������ ���ĵ� vec�� �� ������ ������� ������ ���� ���� ���� �� ���� ��ȯ�Ѵ�.
// �̶� pair.first < pair.second�̴�.
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