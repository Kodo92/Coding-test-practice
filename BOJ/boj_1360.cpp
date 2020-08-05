/*
	[백준] 1360 되돌리기
		문제 출처 : https://www.acmicpc.net/problem/1360

	[풀이 방법] 구현
		1. vector에 시간 순서대로 문자열의 상태와 시간값을 push한다.
			type -> vector.back().string + 문자열
			undo -> time - t 의 시간보다 작은 값들 중 최대값의 문자열.

	[실패 과정]
		???? 같은 로직을 새로 짰을 뿐인데 통과가 됐다...?
			-> 멍청했다... vector.size() == 0 || destTime < 0 일때 continue했는데, vector에 undo push까지 생략되어버렸다.
*/

#include <iostream>
#include <vector>
#include <string>

struct node {
	int time;
	std::string str;
};

int main()
{
	int N;
	std::cin >> N;
	std::vector<node> sequences;

	while(N--)
	{
		std::string type, code;
		int time;
		std::cin >> type >> code >> time;
		if (type == "type")
		{
			if (sequences.empty())
				sequences.push_back({ time,code });
			else
				sequences.push_back({time, sequences.back().str + code });			
		}
		else
		{
			std::string newString;
			int destTime = time - stoi(code);
			for (const auto j : sequences)
			{
				if (j.time >= destTime)
					break;
				newString = j.str;
			}
			sequences.push_back({ time,newString });
		}
	}
	std::cout << sequences.back().str;
	return 0;
}

// TEST CASE
/*
4
type a 1
type b 2
type c 3
undo 3 4
output : ab

*/