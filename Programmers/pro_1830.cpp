/*
	[프로] 브라이언의 고민
		문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/1830
		비고 : 2017 카카오코드 예선
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct node
{
	int startPosition = -1;
	int endPosition = -1;
	int count = 1;
};

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(string sentence) {
	map<char, node> symbols;
	for (int i = 0; i < sentence.size(); i++)
	{
		if (sentence[i] >= 'A' && sentence[i] <= 'Z') continue;
		if (symbols[sentence[i]].startPosition == -1)
		{
			symbols[sentence[i]].startPosition = i;
			symbols[sentence[i]].endPosition = i;
		}
		else
		{
			symbols[sentence[i]].endPosition = i;
			symbols[sentence[i]].count++;
		}
	}
	string answer = "";
	return answer;
}

int main()
{
	//cout << solution("HaEaLaLaObWORLDb") << endl;
	//cout << solution("SpIpGpOpNpGJqOqA") << endl;
	return 0;
}