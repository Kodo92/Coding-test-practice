#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> nums) {
	int answer = 0;

	vector<int> permutation;
	for (int i = 0; i < nums.size(); i++)
	{
		if (i >= nums.size() - 3)
			permutation.push_back(1);
		else
			permutation.push_back(0);
	}

	do
	{
		int sum = 0;
		bool flag = false;
		for (int i = 0; i<permutation.size(); i++)
		{
			if (permutation[i] == 1)
				sum += nums[i];
		}

		for (int i = 2; i*i <= sum; i++)
		{
			if (sum % i == 0)
			{
				flag = true;
				break;
			}
		}
		if (!flag)
			answer++;
	} while (next_permutation(permutation.begin(), permutation.end()));


	return answer;
}