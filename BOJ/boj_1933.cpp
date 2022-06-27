#include <iostream>
#include <queue>
#include <map>
#include <set>
#include <vector>

struct node {
	int idx;
	int height;
	bool isLeft;
};

int main() {

	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	int N;
	std::cin >> N;

	auto cmp = [](const node& a, const node& b) { if (a.idx == b.idx) return !a.isLeft; return a.idx > b.idx; };
	std::priority_queue<node, std::vector<node>, decltype(cmp)> queue(cmp);
	for (int i = 0; i < N; i++) {
		int L, H, R;
		std::cin >> L >> H >> R;
		queue.push({ L,H,true });
		queue.push({ R,H,false });
	}

	std::map<int, int> answer;

	std::multiset<int> heights;
	heights.insert(0);
	int maxHeight = 0;
	while (!queue.empty()) {
		node now = queue.top();
		queue.pop();

		// heights�� insert && maxHeight���� height�� ������ ���� ����
		if (now.isLeft) {
			if ((*heights.rbegin()) < now.height) {
				maxHeight = now.height;
				if(answer[now.idx] < now.height)
					answer[now.idx] = now.height;
			}
			heights.insert(now.height);
		}
		// heights���� remove && maxHeight == now.height ���� ���� ū ������ ����
		else {
			heights.erase(heights.find(now.height));
			if ((*heights.rbegin()) < now.height) {
				maxHeight = (*heights.rbegin());
				if (answer[now.idx] == 0)
					answer[now.idx] = maxHeight;
				if (answer[now.idx] > maxHeight)
					answer[now.idx] = maxHeight;
			}
		}
	}
	
	for (auto iter : answer) {
		std::cout << iter.first << ' ' << iter.second<<' ';
	}

}

/*
�ݷ� 
	- ���� ��ġ�� �ǹ��� ������ : ���� ū ���̸� insert
		2
		1 1 2
		1 2 2

*/