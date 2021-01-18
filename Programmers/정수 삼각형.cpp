#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 7Á¡...

int solution(vector<vector<int>> triangle) {
	int N = triangle.size();
	vector<int> Sums;
	Sums.push_back(triangle[0][0]);

	int sumsSize = 1, sum0 = 0, sum1 = 0, Max = 0;
	for (int i = 1; i < N; i++)
	{
		for (int j = (triangle[i].size() - 1); j >= 0; j--)
		{
			if (j == 0)
				Sums[j] += triangle[i][j];
			else if (j == Sums.size())
				Sums.push_back(Sums[j - 1] + triangle[i][j]);
			else if (j > 0 && j < Sums.size())
			{
				sum0 = Sums[j - 1] + triangle[i][j];
				sum1 = Sums[j] + triangle[i][j];
				(sum0 > sum1) ? Max = sum0 : Max = sum1;
				Sums[j] = Max;
			}
		}
		sumsSize++;
	}

	return *(max_element(Sums.begin(), Sums.end()));
}

int main()
{
	vector<vector<int>> triangle{ 
		{1 },
		{2, 3 },
		{4, 5, 6},
		{7, 8, 9, 10 }, { 11, 12, 13, 14, 15 },
		{16,17,18,19,20,21}
	};
	cout << solution(triangle);
	return 0;
}