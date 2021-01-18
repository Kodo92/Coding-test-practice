#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
	string answer = "";

	auto startIter = number.begin();
	for (int i = number.size() - k-1; i >= 0 && startIter != number.end(); i--)
	{
		startIter = max_element(startIter, number.end() - i);
		answer += *startIter;
		startIter++;
	}

	return  answer;
}

// 다른사람 코드 연구
/*
string solution(string number, int k) {
	string answer = "";
	answer = number.substr(k);
	for (int i = k - 1; i >= 0; i--) {
		int j = 0;
		do {
			if (number[i] >= answer[j]) {
				char temp = answer[j];
				answer[j] = number[i];
				number[i] = temp;
				j++;
			}
			else {
				break;
			}
		} while (1);
	}



	return answer;
}
*/
void main()
{
	cout << solution("4177252841",4);
}
/*
K개의 수를 제거했을 때 얻을 수 있는 가장 큰 숫자를 구한다.
중요한 점은 입력받은 문자열의 순서를 지켜줘야한다. -> SORT() 후 끝 N자리 수 리턴이 아님.
- POINT
N번째 자리수는 끝에서 N개를 제외한 숫자들 중 가장 큰 수이다. 
탐색의 시작점은 I+1번째 자리수 (I < K)에 들어온 숫자 다음부터이다.
*/