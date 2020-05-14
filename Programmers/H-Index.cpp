#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
	int answer = 0;

	sort(citations.begin(), citations.end());

	int Count = 0;
	for(int h=0;h<=citations.size();h++)
	{
		for (Count ; Count < citations.size();Count++)
		{
			if (h <= citations[Count] && citations.size() - Count >= h)
			{
				answer = (answer < h) ? h : answer;
				break;
			}
		}
	}
	return answer;
}

void main()
{

	// if h == 5 -> citationPos : 3, citationSize : 9
	cout << solution({ 1,2,3,4,5,6,7,8,9,10 });
	cout << solution({ 0,1,4,5,6,7 });
	cout << solution({ 0 });
}