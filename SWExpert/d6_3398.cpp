#include<iostream>
#include<vector>

long long sum(std::vector<long long>& tree, int i) {
	long long retVal = 0;
	while (i > 0) {
		retVal += tree[i];
		i -= (i & -i);
	}
	return retVal;
}

void update(std::vector<long long>& tree, int index, int day) {
	while (index < tree.size()) 
	{
		tree[index] += day;
		index += (index & -index);
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	std::cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, D;
		long long s, a, b;
		std::cin >> N >> D >> s >> a >> b;

		std::vector<long long> H(D, 0);
		long long answer = 0;
		int index = 1;
		for (int i = 1; i <= D; i++) {
			int c = s % N + 1;
			s = (s * a + b) % 1000000007;
			int k = s % N + 1;
			s = (s * a + b) % 1000000007;

			update(H, index, i);
			index += c;
			if (index > N) {
				index -= N;
				if (index > 1) {
					update(H, 1, i);
					update(H, index, -i);
				}
			}
			else {
				update(H, index, i * (-1));
			}

			int find = index + k - 1;
			if (find > N) {
				find -= N;
			}
			answer += sum(H, find);
		}
		
		std::cout << "#" << test_case << " " << answer;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}