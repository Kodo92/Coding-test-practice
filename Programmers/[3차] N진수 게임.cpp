#include <iostream>
#include <string>
#include <vector>

using namespace std;

// n : n진수, t : 말해야 하는 횟수, m : 게임에 참가하는 인원, p : 튜브의 순서
string solution(int n, int t, int m, int p) {
	string answer = "";

	int speakCount = 0;
	int tubeSpeakCount = 0;
	int number = 0;

	while (tubeSpeakCount < t)
	{
		vector<int> tempData;
		int tempNumber = number;

		if(tempNumber == 0)
			tempData.push_back(0);

		while (tempNumber > 0)
		{
			tempData.push_back(tempNumber % n);
			tempNumber /= n;
		}

		// number를 n진수로 변환한 결과를 순서대로 말한다.
		for (auto value = tempData.rbegin() ; value != tempData.rend(); value++)
		{
			if (speakCount == (p-1))
			{
				tubeSpeakCount++;
				if(*value >= 10)
					answer += *value + 55;
				else
					answer += to_string(*value);

				if (tubeSpeakCount >= t)
					break;
			}

			speakCount++;
			speakCount %= m;
		}
		number++;
	}
	return answer;
}

/*
number를 n진수로 바꾸는 방법으로 mod연산을 적용하였다.

10부터 A,B,C,D,E,F로 변환하는 것은 int형 값을 char로 변환해 string에 추가해주었다.

*/