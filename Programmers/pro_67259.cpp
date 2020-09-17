/*
	[프로] 경주로 건설
		문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/67259
		비고 : 2020 카카오 인턴십
*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 2147483646;
pair<int, int> direction[]{ {-1,0},{1,0},{0,-1},{0,1} };

struct node
{
	int cost;
	int y, x;
	int direction;
};

auto cmp = [](const node& a, const node& b) { return a.cost > b.cost; };

int solution(vector<vector<int>> board) {
	int N = board.size();

	vector<vector<int>> costs = board;
	queue<node> q;
	q.push({ 0,0,0,-1 });
	board[0][0] = 1;

	int answer = MAX;
	while (!q.empty())
	{
		auto top = q.front();
		int nowCost = top.cost;
		int nowDirection = top.direction;

		q.pop();

		if (top.y == N - 1 && top.x == N - 1)
			answer = (answer > nowCost) ? nowCost : answer;

		for (int i = 0; i < 4; i++)
		{
			int newY = top.y + direction[i].first;
			int newX = top.x + direction[i].second;
			int newCost = nowCost + 100;

			if (nowDirection != i && nowDirection != -1)
				newCost += 500;

			if (newY < 0 || newY >= N || newX < 0 || newX >= N) continue;
			if (board[newY][newX] == 1) continue;
			if (board[newY][newX] != 0 && board[newY][newX] < newCost) continue;
			board[newY][newX] = newCost;
			q.push({ newCost,newY,newX,i });
		}
	}
	return answer;
}

int main()
{
	cout << solution({ {0,0,0},{0,0,0},{0,0,0} }) << endl;
	//cout << solution({ {0, 0, 1, 0},{0, 0, 0, 0},{0, 1, 0, 1},{1, 0, 0, 0} }) << endl;

	return 0;
}