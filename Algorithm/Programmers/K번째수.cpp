#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;

	for (auto i : commands)
	{
		vector<int> copyVector(array.begin()+(i[0]-1), array.begin()+i[1]);	
		sort(copyVector.begin(), copyVector.end());
		answer.push_back(copyVector[(i[2]-1)]);
	}

	return answer;
}

void main()
{
	solution({ 1,5,2,6,3,7,4 }, { {2,5,3},{4,4,1},{1,7,3} });
}