#include <iostream>
#include <vector>
#include <string>

char colors[]{ 'w','y','r','o','g','b' };
char pageChar[]{ 'U','D','F','B','L','R' };

int rotationCondition[][5][3]{	{ { 2,1,0 },{ 4,1,0 },{ 3,1,2 },{ 5,1,0 },{ 2,1,0 } },			// U
											{ { 2,1,2 },{ 5,1,2 },{ 3,1,0 },{ 4,1,2 },{ 2,1,2 } },			// D
											{ { 0,1,2 },{ 5,-1,0 },{ 1,1,0 },{ 4,-1,2 },{ 0,1,2 } },			// F
											{ { 0,1,0 },{ 4,-1,0 },{ 1,1,2 },{ 5,-1,2 },{ 0,1,0 } },			// B
											{ { 0,-1,0 },{ 2,-1,0 },{ 1,-1,0 },{ 3,-1,2 },{ 0,-1,0 } },		// L
											{ { 0,-1,2 },{ 3,-1,2 },{ 1,-1,2 },{ 2,-1,2 },{ 0,-1,2 } }, };	// R


void print(std::vector<std::vector<std::vector<int>>>& cube)
{
	for (const auto i : cube[0])
	{
		for (const auto j : i)
			std::cout << colors[j];
		std::cout << '\n';
	}
}

void copyData(std::pair<int,int> conditionIndex, std::vector<std::vector<std::vector<int>>>& cube, std::vector<int>& dest)
{
	// conditionIndex.first = 기준 면 / conditionIndex.second = rotationCondition[conditionIndex.first][conditionIndex.second] 
	int index = conditionIndex.first;
	int subIndex = conditionIndex.second;
	int* condition = rotationCondition[index][subIndex];
	if (condition[1] == 1)	// 가로
	{
		for (int i = 0; i < 3; i++)
			dest[i] = cube[condition[0]][condition[2]][i];
	}
	else
	{
		// 세로
		for (int i = 0; i < 3; i++)
			dest[i] = cube[condition[0]][i][condition[2]];
	}
}

void copyData(std::vector<int>& source, std::vector<int>& dest)
{
	for (int i = 0; i < 3; i++)
		dest[i] = source[i];
}

void setData(std::pair<int,int> conditionIndex, int prevIndex, std::vector<int>& source, std::vector<std::vector<std::vector<int>>>& dest)
{
	int index = conditionIndex.first;
	int subIndex = conditionIndex.second;
	int* condition = rotationCondition[index][subIndex];
	int* prevCondition = rotationCondition[index][prevIndex];
	if (condition[1] == 1)	// 가로
	{
		if (condition[1] == prevCondition[1])	// 가로 -> 가로
		{
			for (int i = 0; i < 3; i++)
				dest[condition[0]][condition[2]][i] = source[i];
		}
		else // 세로 -> 가로
		{
			for (int i = 0; i < 3; i++)
				dest[condition[0]][condition[2]][i] = source[2-i];
		}
	}
	else // 세로
	{
		if (condition[1] == prevCondition[1])	// 세로 -> 세로
		{
			for (int i = 0; i < 3; i++)
				dest[condition[0]][i][condition[2]] = source[i];
		}
		else // 가로 -> 세로
		{
			for (int i = 0; i < 3; i++)
				dest[condition[0]][i][condition[2]] = source[2-i];
		}
	}
}

void rotation(std::vector<std::vector<std::vector<int>>>& cube, int cubeIndex, bool clockwise)
{
	std::vector<int> prev(3), next(3);
	
	if (clockwise)	// 시계방향
	{
		copyData({ cubeIndex,0 }, cube, prev);
		copyData({ cubeIndex,1 }, cube, next);

		for (int i = 1; i < 5; i++)
		{
			setData({ cubeIndex,i },i-1, prev, cube);
			copyData(next, prev);
			if (i + 1 < 5)
				copyData({ cubeIndex,(i + 1) }, cube, next);
		}
	}
	else
	{
		copyData({ cubeIndex,4 }, cube, prev);
		copyData({ cubeIndex,3 }, cube, next);

		for (int i = 3; i >= 0; i--)
		{
			setData({ cubeIndex,i },i+1, prev, cube);
			copyData(next, prev);
			if (i - 1 >= 0)
				copyData({ cubeIndex,(i - 1) }, cube, next);
		}
	}
}

void proc(std::vector<std::string>& conditions)
{
	// cube initialize
	std::vector<std::vector<std::vector<int>>> cube(6,std::vector<std::vector<int>>(3,std::vector<int>(3)));
	for (int i = 0; i < 6; i++)
	{
		for (int y = 0; y < 3; y++)
		{
			for (int x = 0; x < 3; x++)
				cube[i][y][x] = i;
		}
	}

	for (const auto value : conditions)
	{
		int i = 0;
		for (; i < 6; i++)
		{
			if (pageChar[i] == value[0])
				break;
		}

		if (value[1] == '-')	 // 반시계
			rotation(cube, i, false);
		else
			rotation(cube, i,true);
	}
	print(cube);
}

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	int N;
	std::cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		int M;
		std::cin >> M;
		std::vector<std::string> conditions;
		for (int j = 0; j < M; j++)
		{
			std::string str;
			std::cin >> str;
			conditions.push_back(str);
		}
		proc(conditions);
	}
}