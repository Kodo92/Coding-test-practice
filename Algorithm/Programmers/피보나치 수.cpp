#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int answer = 0;

	vector<int> fibonach{ 0,1 };

	for (int i = 2; i <= n; i++)
		fibonach.push_back((fibonach[i - 2] + fibonach[i - 1]) % 1234567);

	return fibonach[n];
}