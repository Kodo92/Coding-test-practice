/*
	[����] �� �� �̾Ƽ� ���ϱ�
		���� ��ó : https://programmers.co.kr/learn/courses/30/lessons/68644
		��� : ���� �ڵ� ç���� ���� 1 - 9��
*/

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
	std::vector<int> permutation(numbers.size(), 0);
	permutation[numbers.size() - 1] = 1;
	permutation[numbers.size() - 2] = 1;
	
	set<int> sumValues;
	do
	{
		int sum = 0;
		for (int i = 0; i < permutation.size(); i++)
		{
			if (permutation[i] == 1)
				sum += numbers[i];
		}

		sumValues.insert(sum);
	} while (next_permutation(permutation.begin(), permutation.end()));

	vector<int> answer;
	for (const auto& i : sumValues)
		answer.push_back(i);
	return answer;
}

int main()
{

	return 0;
}