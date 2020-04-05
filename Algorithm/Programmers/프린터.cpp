#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;
	vector<int> tempPriorities = priorities;
	queue<int>  indexQ;
	auto maxValue = max_element(tempPriorities.begin(), tempPriorities.end());
	for (int i = 0; i<priorities.size(); i++)
		indexQ.push(i);

	int printedIndex = 0, loopCount = 0;
	while (!indexQ.empty())
	{
		printedIndex = indexQ.front();
		indexQ.pop();
		if (priorities[printedIndex] == *maxValue)
		{
			loopCount++;
			if (printedIndex == location)
				return loopCount;
			tempPriorities.erase(maxValue);
			maxValue = max_element(tempPriorities.begin(), tempPriorities.end());
		}
		else
			indexQ.push(printedIndex);


	}
	return answer;
}

int main()
{
	cout << solution({ 1,1,9,1,1,1 }, 0);
	return 0;
}