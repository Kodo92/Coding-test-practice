#include <iostream>
#include <string>
#include <vector>

using namespace std;

int find(vector<int>& parents, int index)
{
	if (parents[index] == index)
		return index;
	return parents[index] = find(parents, parents[index]);
}

void merge(vector<int>& parents, int leftIndex, int rightIndex)
{
	parents[rightIndex] = leftIndex;
}

int solution(int n, vector<vector<int>> computers) {
	int answer = n;
	vector<int> parents(n);
	for (int i = 0; i < n; i++)
		parents[i] = i;

	for (int i = 0; i < n; i++)
	{
		int indexParent = find(parents, i);
		for (int j = 0; j < n; j++)
		{
			if (i == j || computers[i][j] == 0) continue;
			int secondParent = find(parents, j);
			if (indexParent == secondParent) continue;
			merge(parents, indexParent, secondParent);
			answer--;
		}
	}

	return answer;
}

int main()
{
	cout << solution(3, { {1,1,0},{1,1,0},{0,0,1} });


	return 0;
}