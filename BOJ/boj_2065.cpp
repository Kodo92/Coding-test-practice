#include <iostream>
#include <vector>
#include <string>
#include <queue>

struct node {
	int idx;
	long long time;
};

// M : ������ �ִ� M���� ����� �¿� �� �ִ�.
// t : ����谡 �ٸ� ���������� �̵��ϴµ� t�� �ð��� �ɸ���. (���� ���)
// N : �մ��� ��
int M, t, N;

std::vector<std::vector<node>> dirs(2, std::vector<node>());
std::vector<std::queue<node>> waitConsumer(2,std::queue<node>());
// �մ��� �¿�µ� �ҿ�� �ð� (�մ��� ������̾��ٸ� 0�� ����)
// dir, time
std::pair<int,long long> checkConsumer(int dir, const long long nowTime) {
	// 1. dir�� �¿� �մ��� ���� ���� ������ ���
	int nextDir = (dir + 1) % 2;
	std::queue<node>& nowQ = waitConsumer[dir];
	std::queue<node>& nextQ = waitConsumer[nextDir];
	if (nowQ.empty()) {
		// �ݴ����� �� ��� �ִ� ���
		return { nextDir, ((nextQ.front().time < nowTime) ? nowTime : nextQ.front().time) + t };
	}

	// dir�� �մ��� �� ������ �ִ� ���
	// ���� �ٷ� �¿� �մ��� �ִ� ���
	if (nowQ.front().time <= nowTime)
		return { dir, nowTime };
	// �ݴ����� ���� ���� ���
	else if (!nextQ.empty() && nowQ.front().time > nextQ.front().time) {
		return { nextDir, ((nextQ.front().time < nowTime) ? nowTime : nextQ.front().time) + t };
	}
	// ���� ���⿡�� �մ��� ��� ���
	else
		return { dir, nowQ.front().time };
}

void rideBoat(std::vector<int>& answer, int dir, long long nowTime) {
	std::queue<node>& now = waitConsumer[dir];
	for (int i = 0; i < M && !now.empty(); i++) {
		if(now.front().time > nowTime)
			break;
		answer[now.front().idx] = nowTime + t;
		now.pop();
	}
}

int main() {

	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	
	std::cin >> M >> t >> N;

	std::vector<int> answer(N, 0);
	std::queue<int> boat;
	
	for (int i = 0; i < N; i++) {
		int time;
		std::string dir;
		std::cin >> time >> dir;
		int idx = (dir == "left") ? 0 : 1;
		waitConsumer[idx].push({ i,time });
	}

	int count = 0;
	long long nowTime = 0;
	int nowDir = 0;
	while (!waitConsumer[0].empty() || !waitConsumer[1].empty()) {
		auto next = checkConsumer(nowDir, nowTime);
		nowTime = next.second;
		rideBoat(answer, next.first, nowTime);
		nowTime += t;
		nowDir = (next.first+1)%2;
	}

	for (int i : answer) {
		std::cout << i << '\n';
	}

	return 0;
}

/*
2 10 5
0 left
0 left
0 left
0 left
0 left

10
10
30
30
50

10 100 3
0 left
10 left
110 right

100 
300
400

3 5 9
0 left
100 right
200 left
300 right
400 right
500 right
600 left
700 left
800 left

5
105
205
305
410
510
605
710
810
*/
