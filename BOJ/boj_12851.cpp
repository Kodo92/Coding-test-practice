/*
[백준 12851] 숨바꼭질 2
	출처 : https://www.acmicpc.net/problem/12851
*/

#include <iostream>
#include <vector>
#include <queue>
#include <set>

struct node {
	int cost;
	int pos;
};

std::pair<int, int> BFS(const int start, const int dest) {

	auto comp = [](const node& a, const node& b) {		return a.cost > b.cost; 	};

	int isVisited[100001] = { 0, };

	std::priority_queue<node, std::vector<node>, decltype(comp)> queue(comp);
	queue.push({ 0,start });

	int minCost = 2147483647;
	int answer = 0;

	while (!queue.empty()) {
		auto now = queue.top();
		queue.pop();

		isVisited[now.pos] = true;

		if (minCost < now.cost)
			break;

		if (now.pos == dest) {
			minCost = now.cost;
			answer++;
			continue;
		}

		if ((now.pos-1) >= 0 && !isVisited[now.pos-1])
			queue.push({ now.cost + 1,now.pos - 1 });
		if ((now.pos + 1) <= 100000 && !isVisited[now.pos + 1])
			queue.push({ now.cost + 1,now.pos + 1 });
		if ((now.pos * 2) <= 100000 && !isVisited[now.pos * 2])
			queue.push({ now.cost + 1,now.pos * 2 });
	}
	return { minCost,answer };
}

int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	int start, dest;
	std::cin >> start >> dest;

	std::pair<int, int> answer = BFS(start, dest);
	std::cout << answer.first << '\n' << answer.second;
	return 0;
}