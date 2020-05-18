#include <vector>

using namespace std;

int solution(int n) {

	vector<int> fibonacci{ 1,2 };

	for (int i = 2; i<n; i++)
		fibonacci.push_back((fibonacci[i - 2] + fibonacci[i - 1]) % 1000000007);

	return fibonacci[n - 1];
}