#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// √÷¥Î 0.01ms
/*
vector<int> solution(vector<int> heights) {
	vector<int> answer;
	stack<int> Tops;

	answer.resize(heights.size());

	int frontIndex = heights.size();
	for (int i = heights.size() - 2; i >= 0; i--)
	{
		for (int j = (i + 1); j <frontIndex; j++)
			if (answer[j] == 0)
				Tops.push(j);
		while (!Tops.empty())
		{
			if (heights[Tops.top()] < heights[i])
			{
				frontIndex = (i + 1);
				answer[Tops.top()] = frontIndex;
			}
			Tops.pop();
		}
	}
	return answer;
}
*/

vector<int> solution(vector<int> heights) {
	vector<int> answer;

	return answer;
}

void main()
{
	solution({1,5,3,6,7,6,5});


}