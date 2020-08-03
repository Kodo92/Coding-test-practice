/*
	[백준] 9202. Boggle
		문제 출처 : https://www.acmicpc.net/problem/9202

	[풀이 방법] DFS + 약간의 trie?
		1. 사전 문자열을 dictionary set에 넣고 TRIE방식으로 문자열을 분해해 trie set에 넣는다.
		2. 4x4의 문자에 대해 DFS 실행
			- 8방향으로 탐색하는데 덧붙여진 문자가 trie에 존재하지 않으면 패스.

	[실패 과정]
		1. BFS에서 방문한 위치는 재방문 X
		2. BFS -> DFS로 변경 : 시간초과
			- isUsed 체크때 AC -> M / AM이 있을 경우 AC->M이 방문했기에 불가능하다.
		3. 찾은 문자열들을 map으로 사이즈별 관리했지만 시간초과문제로 answerSize, answer string으로 변경. : 시간초과
		4. dfs 탈출 조건을 문자열 길이가 8인경우가 아니라 dictionary의 제일 긴 문자열의 길이로 조건 변경 : 정답
		5. 최초 dfs 시작하기 전에 시작 문자가 trie에 속하는지 체크 -> 20ms 시간 감소

	[풀이 일자] 2020.08.03.
*/

#include <iostream>
#include <vector>
#include <string>
#include <set>

std::pair<int, int> direction[]{ {-1,0},{-1,-1}, {0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1} };	// UU, UL, LL, DL, DD, DR, RR, UR
std::set<std::string> dictionary;
std::set<std::string> trie;
std::set<std::string> answerList;
int answerSize = 0;
int maxStringSize = 0;
std::string answer;

int score = 0;
int getScore(const int stringSize)
{
	if (stringSize <= 2)
		return 0;
	else if (stringSize <= 4)
		return 1;
	else if (stringSize == 5)
		return 2;
	else if (stringSize == 6)
		return 3;
	else if (stringSize == 7)
		return 5;
	else if (stringSize == 8)
		return 11;
}

void dfs(const std::vector<std::string>& board, std::vector<std::vector<bool>>& isUsed, std::string str, std::pair<int, int> position)
{
	if (dictionary.find(str) != dictionary.end())
	{
		if (answerList.find(str) == answerList.end())
		{
			score += getScore(str.size());
			answerList.insert(str);
			if (answerSize < str.size())
			{
				answer = str;
				answerSize = str.size();
			}
			else if (answerSize == str.size())
			{
				if (answer > str)
					answer = str;
			}
		}
	}

	if (str.size() == maxStringSize)
		return;

	for (int i = 0; i < 8; i++)
	{
		int newY = position.first + direction[i].first;
		int newX = position.second + direction[i].second;
		if (newY < 0 || newY >= 4 || newX < 0 || newX >= 4) continue;
		if (isUsed[newY][newX]) continue;
		std::string newString = str +  board[newY][newX];
		if (trie.find(newString) == trie.end())
			continue;
		isUsed[newY][newX] = true;
		dfs(board, isUsed, newString, { newY,newX });
		isUsed[newY][newX] = false;

	}
}

int main()
{
	int W, B;
	std::cin >> W;

	for (int i = 0; i < W; i++)
	{
		std::string input;
		std::cin >> input;
		dictionary.insert(input);
		maxStringSize = (maxStringSize < input.size()) ? input.size() : maxStringSize;
		for(int j=0;j<input.size();j++)
			trie.insert(input.substr(0,1+j));
	}


	std::cin >> B;
	while (B--)
	{
		std::vector<std::string> board(4);
		for (int i = 0; i < 4; i++)
			std::cin >> board[i];

		answerList.clear();
		answer.clear();
		score = 0;
		answerSize = 0;
		answer = "";
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				std::vector<std::vector<bool>> isUsed(4, std::vector<bool>(4, false));
				std::string startString = board[i].substr(j, 1);
				if (trie.find(startString) == trie.end()) continue;
				isUsed[i][j] = true;
				dfs(board, isUsed, startString, { i,j });
				isUsed[i][j] = false;
			}
		}

		std::cout << score << ' ' << answer << ' ' << answerList.size() << '\n';
	}
}
/*

1
ABA
1
ABCD
EFGH
IJKL
MNOP
*/