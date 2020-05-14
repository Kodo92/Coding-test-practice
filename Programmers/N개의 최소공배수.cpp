#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
	int r = 0;
	while (a != 0)
	{
		r = b%a;
		b = a;
		a = r;
	}
	return b;
}

int solution(vector<int> arr) {
	int answer = 0;

	answer = arr[0];
	for (int i = 1; i<arr.size(); i++)
		answer = (answer * arr[i] / gcd(answer, arr[i]));
	return answer;
}