/*
	[프로] 자물쇠와 열쇠
		문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/60059
		비고 : 200 KAKAO BLIND RECURITMENT
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void rotateKey(vector<vector<vector<int>>>& rotatedKey)
{
	int offset = rotatedKey.front().size() - 1;
	int size = offset + 1;
	for (int i = 1; i < 4; i++)
	{
		for (int a = 0; a < size; a++)
		{
			for (int b = 0; b < size; b++)
				rotatedKey[i][a][b] = rotatedKey[i - 1][offset - b][a];
		}
	}
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	int lockSize = lock.size();
	int paddingSize = key.size() - 1;
	int totalSize = lockSize + paddingSize * 2;
	int holeCount = 0;
	vector<vector<int>> paddingLock(totalSize, vector<int>(totalSize,0));

	for (int i = 0; i < lockSize; i++)
	{
		for (int j = 0; j < lockSize; j++)
		{
			paddingLock[i + paddingSize][j + paddingSize] = lock[i][j];
			if (lock[i][j] == 0)
				holeCount++;
		}
	}

	vector<vector<vector<int>>> rotatedKey(4, vector<vector<int>>(key.size(), vector<int>(key.size())));
	rotatedKey[0] = key;
	rotateKey(rotatedKey);

	for (int i = 0; i < lockSize + paddingSize; i++)
	{
		for (int j = 0; j < lockSize + paddingSize; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				int tempCount = 0;
				bool isFalse = false;
				for (int a = 0; a < key.size(); a++)
				{
					if (isFalse) break;
					for (int b = 0; b < key.size(); b++)
					{
						if (a + i >= paddingSize && a + i < lockSize + paddingSize && b + j >= paddingSize && b + j < lockSize + paddingSize)
						{
							if (paddingLock[a + i][b + j] == 1 && rotatedKey[k][a][b] == 1)
							{
								isFalse = true;
								break;
							}
							if (paddingLock[a + i][b + j] == 0 && rotatedKey[k][a][b] == 1)
								tempCount++;
						}
					}
				}
				if (tempCount == holeCount)
					return true;
			}

		}
	}
	return false;
}

int main()
{
	cout << solution({ {0,0,0},{1,0,0},{0,1,1} }, { {1,1,1},{1,1,0},{1,0,1} }) << endl;

	return 0;
}