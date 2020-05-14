#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer;
	vector<int> tempAnswer;

	for (int i=0;i<prices.size();i++)
	{
		answer.push_back(0);

		for (int j = 0; j<tempAnswer.size(); )
		{
			answer[tempAnswer[j]]++;
			if (prices[tempAnswer[j]] > prices[i])
				tempAnswer.erase(tempAnswer.begin() + j);
			else
				j++;
		}
		tempAnswer.push_back(i);
	}

	return answer;
}

int main()
{
	solution( {2,3,1} );


	return 0;
}
