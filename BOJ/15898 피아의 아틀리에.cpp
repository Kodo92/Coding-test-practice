#include <iostream>
#include <vector>
#include <algorithm>

int N;
int max;

struct cauldronType
{
	int effect = 0;
	char quality = 'W';
};

cauldronType inputs[10][4][4][4];

std::pair<int, int> position[] = { {0,0},{0,1},{1,0},{1,1} };

int calQuality(const std::vector<std::vector<cauldronType>> cauldron)
{
	//	 R B G Y W
	int counts[5]{ 0,0,0,0,0 };
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (cauldron[i][j].quality == 'R')
				counts[0] += cauldron[i][j].effect;
			else if (cauldron[i][j].quality == 'B')
				counts[1] += cauldron[i][j].effect;
			else if (cauldron[i][j].quality == 'G')
				counts[2] += cauldron[i][j].effect;
			else if (cauldron[i][j].quality == 'Y')
				counts[3] += cauldron[i][j].effect;
			else
				counts[4] += cauldron[i][j].effect;
		}
	}

	int retVal = 0;
	retVal += (counts[0] * 7);
	retVal += (counts[1] * 5);
	retVal += (counts[2] * 3);
	retVal += (counts[3] * 2);

	return retVal;
}

auto makeMaterial(int pos, const cauldronType value[][4])
{
	std::vector<std::vector<cauldronType>> newVec(5,std::vector<cauldronType>(5,cauldronType()));
	
	int y = position[pos].first;
	int x = position[pos].second;

	for (int i=0;i<4;i++)
	{
		for (int j=0;j<4;j++)
			newVec[i + y][j + x] = value[i][j];
	}

	return newVec;
}

std::vector<std::vector<cauldronType>> cal(std::vector<std::vector<cauldronType>>& cauldron, std::vector<std::vector<cauldronType>>&& value)
{
	std::vector<std::vector<cauldronType>> newVec(cauldron);
	if (value.size() != 0)
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				newVec[i][j].effect += value[i][j].effect;
				if (newVec[i][j].effect < 0) newVec[i][j].effect = 0;
				if (newVec[i][j].effect > 9) newVec[i][j].effect = 9;
				if (value[i][j].quality != 'W')
					newVec[i][j].quality = value[i][j].quality;
			}
		}
	}
	return newVec;
}

void dfs(std::vector<std::vector<cauldronType>> cauldron, int count, std::vector<bool> isUsed)
{
	if (count >= 3)
	{
		max = std::max(max, calQuality(cauldron));
		return;
	}

	for (int i = 0; i < N; i++)
	{
		if (isUsed[i]) continue;
		isUsed[i] = true;
		// 4방향
		for (int j = 0; j < 4; j++)
		{
			// 4회전
			for(int k=0;k<4;k++)
				dfs(cal(cauldron, makeMaterial(j,inputs[i][k])), count + 1, isUsed);
		}
		isUsed[i] = false;
		
	}
}

void rotation(const int inputNumber)
{
	for (int i = 1; i < 4; i++)
	{
		auto& temp = inputs[inputNumber][i];
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
				temp[j][k] = inputs[inputNumber][i-1][3-k][j];
		}
	}
}

int main()
{
	std::cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 4; j++)
			for (int k = 0; k < 4; k++)
				std::cin >> inputs[i][0][j][k].effect;

		for (int j = 0; j < 4; j++)
			for (int k = 0; k < 4; k++)
				std::cin >> inputs[i][0][j][k].quality;

			rotation(i);
	}

	std::vector<std::vector<cauldronType>> cauldron(5,std::vector<cauldronType>(5,cauldronType()));
	std::vector<bool> isUsed(N, false);

	dfs(cauldron, 0, isUsed);
	std::cout << max;

}