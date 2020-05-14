#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	deque<int> bucket;

	int doll = 0;
	for (auto i : moves)
	{
		i -= 1;
		for (auto& crane : board)
		{
			if (crane[i] != 0)
			{
				doll = crane[i];
				crane[i] = 0;
				if (bucket.empty() || bucket.back() != doll)
					bucket.push_back(doll);
				else
				{
					bucket.pop_back();
					answer += 2;
				}

				break;
			}
		}
	}

	return answer;
}

void main()
{
	cout << solution({ {0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1} }, { 1,5,3,5,1,2,1,4 });
}