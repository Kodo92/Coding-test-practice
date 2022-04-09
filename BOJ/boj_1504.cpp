#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INTEGER_MAX = 2147483647;

int N, E, V1, V2;

struct node {
	int cost;
	int idx;
};
int BFS(const vector<vector<pair<int, int>>>& path, const int startIdx, const int endIdx) {
	vector<int> costs(N, INTEGER_MAX);

	auto cmp = [](const node& a, const node& b) {
		return a.cost > b.cost;
	};

	// cost, idx
	priority_queue<node, vector<node>, decltype(cmp)> q(cmp);
	q.push({ 0,startIdx });
	costs[startIdx] = 0;

	while (!q.empty()) {
		node now = q.top();
		q.pop();

		if (now.idx == endIdx)
			return now.cost;

		for (auto iter : path[now.idx]) {
			int newCost = iter.second + now.cost;
			if (costs[iter.first] > newCost) {
				costs[iter.first] = newCost;
				q.push({ newCost,iter.first });
			}
		}

	}
	return -1;
}

int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> E;
	vector<vector<pair<int, int>>> paths(N, vector<pair<int, int>>());

	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		paths[a - 1].push_back({ b - 1,c });
		paths[b - 1].push_back({ a - 1,c });
	}

	cin >> V1 >> V2;
	V1 -= 1;
	V2 -= 1;
	int oneToV1 = BFS(paths, 0, V1);
	int oneToV2 = BFS(paths, 0, V2);
	int V1toV2 = BFS(paths, V1, V2);
	int V1toN = BFS(paths, V1, N - 1);
	int V2toN = BFS(paths, V2, N - 1);

	if (oneToV1 == -1 && oneToV2 == -1)
		cout << -1;
	else if (V1toN == -1 && V2toN == -1)
		cout << -1;
	else if (V1toV2 == -1)
		cout << -1;
	else 
		cout << min(oneToV1 + V1toV2 + V2toN, oneToV2 + V1toV2 + V1toN);

	return 0;
}