#include <iostream>
#include <array>
#include <string>

std::string rolls;
std::array<std::string,2> bridges;
unsigned int caches[101][2][21];	// [bridges index] [birdges type] [rolls index]

int bridgeSize;

unsigned int dfs(int startIndex, int bridgeType, int rollsIndex)
{
	auto& ref = caches[startIndex-1][bridgeType][rollsIndex];

	if (ref != 0) return ref;
	
	if (rollsIndex >= rolls.size())				// 마법의 두루마리 순서대로 다 건넌 경우 
		return ref = 1;
	if (startIndex >= bridgeSize)				// 마법의 두루마리 순서대로 건너지 못했는데 다리가 끝난 경우
		return ref = 0;

	unsigned int count = 0;
	for (int i = startIndex; i < bridgeSize; i++)
	{
		if (bridges[bridgeType][i] == rolls[rollsIndex])
			count += dfs(i + 1, (bridgeType + 1) % 2, rollsIndex + 1);
	}

	return ref = count;
}

int main()
{
	std::cin.tie(0);
	std::ios_base::sync_with_stdio(false);

	std::cin >> rolls;


	std::cin >> bridges[0];	// devil bridge
	std::cin >> bridges[1];	// engel bridge

	bridgeSize = bridges[0].size();

	std::cout << dfs(0,0,0) + dfs(0,1,0);

	return 0;
}

/*
2차원 DP는 x 이유는?
*/