#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(int N) {
	long long answer = 0;

	vector<long long>Lengths {1, 1};

	for (int i = 2; i < N; i++)
		Lengths.push_back((Lengths[i - 2] + Lengths[i - 1]));

	answer = ((Lengths[N-1] *2 )  + Lengths[N-2]) * 2;
	return answer;
}

int main()
{

	cout << solution(80);
	return 0;
}