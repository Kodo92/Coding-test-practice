#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int solution(vector<vector<int> > land)
{
	int max = 0, calval = 0;
	for (int i = 1; i<land.size(); i++)
	{
		for (int j = 0; j<4; j++)
		{
			max = 0;
			for (int k = 0; k<4; k++)
			{
				if (j == k)
					continue;
				calval = land[i - 1][k] + land[i][j];
				if (max < calval)
					max = calval;
			}
			land[i][j] = max;
		}
	}

	return *max_element(land.back().begin(), land.back().end());
}

// land의 원소들 마다 최대값을 계산한 다음 마지막 줄 의 최대값 리턴.

void main()
{
	cout << solution({{ 1,2,3,5 }, { 5,6,7,8 }, { 4,3,2,1 }});

}