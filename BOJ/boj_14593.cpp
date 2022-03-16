/*
[백준 14593] 2017 아주대학교 프로그래밍 경시대회 (Large)
	출처 : https://www.acmicpc.net/problem/14593
*/

#include <iostream>
#include <vector>
#include <algorithm>

struct node {
	int no;
	int score;
	int count;
	int time;
};

int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	int N;
	std::cin >> N;

	std::vector<node> participants(N);
	for (size_t i = 0; i < N; i++)
	{
		participants[i].no = i + 1;
		std::cin >> participants[i].score >> participants[i].count >> participants[i].time;
	}
	auto cmp = [](const node& a, const node&b) {
		if (a.score == b.score) {
			if (a.count == b.count) {
				return a.time < b.time;
			}
			return a.count < b.count;
		}
		return a.score > b.score;
	};
	std::sort(participants.begin(), participants.end(), cmp);
	std::cout << participants.begin()->no;
}