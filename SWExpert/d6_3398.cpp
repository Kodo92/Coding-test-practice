#include<iostream>
#include<vector>
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

		std::vector<int> C(D);
		std::vector<int> K(D);
		std::vector<int> H(D, 0);
		long long sum = 0;
		for (int i = 0; i < D; i++) {
			C[i] = s % N + 1;
			s = (s * a + b) % 1000000007;
			K[i] = s % N + 1;
			s = (s * a + b) % 1000000007;
		}

		int position = 0;
		int day = 1;
		while (day <= N) {
			for (int i = 0; i < C[day - 1]; i++) {
				H[(position + i) % D] += day;
			}
			position = (position + C[day - 1]) % D;
			sum += H[(position + K[day - 1] - 1) % D];

			day++;
		}
		std::cout << "#" << test_case << " " << sum;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}