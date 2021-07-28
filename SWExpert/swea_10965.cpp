#include <iostream>
#include <vector>
int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	const int MAX = 10000000;
	int T;
	std::cin >> T;

	std::vector<int> primeNumbers;
	std::vector<bool> temp(MAX + 1, true);
	for (int i = 2; (i * i) <= MAX; i++) {
		if (temp[i]) {
			primeNumbers.push_back(i);
			for (int j = i * i; j <= MAX; j += i)
				temp[j] = false;
		}
	}

	int primeSize = primeNumbers.size();
	for (int test_case = 1; test_case <= T; test_case++)
	{
		int A;
		std::cin >> A;
		int answer = 1;

		if (temp[A]) {
			std::cout << "#" << test_case << " " << A << '\n';
			continue;
		}

		int index = 0;
		while (A > 1 && index < primeSize) {
			int count = 0;
			while (A % primeNumbers[index] == 0) {
				count++;
				A /= primeNumbers[index];
			}
			if (temp[A]) {
				answer *= A;
				break;
			}
			if (count % 2 != 0)
				answer *= primeNumbers[index];
			index++;
		}
		// MAX의 루트 값보다 큰 소수인 경우가 있을 수 있음 ex) 1000001
		if (A != 1 && index == primeSize)
			answer *= A;
		std::cout << "#" << test_case << " " << answer << '\n';
	}
	return 0;
}