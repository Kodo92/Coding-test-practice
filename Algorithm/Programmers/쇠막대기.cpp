#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

// Max process time : 0.5ms / maximum usage memory : 4.11MB
/*
int solution(string arrangement) {
	int answer = 0;
	int barCount = 0;
	bool openFlag = false;
	for (int i = 0; i<arrangement.size(); i++)
	{
		if (arrangement[i] == '(')
		{
			openFlag = true;
			barCount++;
			answer++;
		}
		else if (arrangement[i] == ')')
		{
			if (openFlag)
			{
				answer--;
				barCount--;
				answer += barCount;
				openFlag = false;
			}
			else
				barCount--;

		}
	}
	return answer;
}
*/

// maximum process time : 0.60ms / maximum usage memory : 4.09MB
int solution(string arrangement) {
	int answer = 0;
	stack<char> Stack;

	for (int i = 0; i<arrangement.size(); i++)
	{
		if (arrangement[i] == '(')
			Stack.push(arrangement[i]);
		else
		{
			Stack.pop();
			if (arrangement[i - 1] == '(')
				answer += Stack.size();
			else
				answer++;
		}
	}
	return answer;
}

void main()
{
	cout << solution("()(((()())(())()))(())");
}