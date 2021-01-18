/*
	[프로그래머스] 17677 뉴스 클러스터링
		문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/17677

	[풀이 방법]
		1. 매개변수로 들어온 두 문자열을 대문자로 변경한다.
		2. 매개변수로 들어온 문자열을 두 글자씩 끊어서 multiset에 넣어준다.
			- set을 사용한 이유는 교집합을 찾을 때 이분탐색으로 빠르게 찾기 위해서 사용.
			- 다중 집합이므로 중복을 허용한다 -> multiset사용
		3. str1 다중 집합의 원소 중 str2 다중 집합이 보유하고 있는 원소는 교집합이다.
			- 다중 집합이기 때문에 중복이 있다. 만약 str2에 존재한다면 str2에서 그 원소를 삭제해준다.
			- 이때 erase를 사용한다면 같은 키를 가진 여러개의 원소들이 동시에 사라짐을 주의하자.
		4. 교집합의 갯수와 합집합의 갯수를 나눈다.
			- size()함수는 size_t 자료형이다. 이는 8바이트 int형과 같으므로 double형변환을 해준다.

*/

#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int solution(string str1, string str2) {

	multiset<string> str1Group, str2Group;

	transform(str1.begin(), str1.end(), str1.begin(), [](unsigned char c) -> unsigned char {return toupper(c); });
	transform(str2.begin(), str2.end(), str2.begin(), [](unsigned char c) -> unsigned char {return toupper(c); });
	for (int i = 0; i < (str1.size()-1); i++)
	{
		if (str1[i] >= 'A' && 'Z' >= str1[i] && str1[i + 1] >= 'A' && str1[i + 1] <= 'Z')
		{
			str1Group.insert(str1.substr(i, 2));
		}
	}
	for (int i = 0; i < (str2.size() - 1); i++)
	{
		if (str2[i] >= 'A' && 'Z' >= str2[i] && str2[i + 1] >= 'A' && str2[i + 1] <= 'Z')
		{
			str2Group.insert(str2.substr(i, 2));
		}
	}

	double answer = 1;
	if (str1Group.size() != 0 || str2Group.size() != 0)
	{
		multiset<string>  unionSection;
		multiset<string>  interSection;
		for (const auto& i : str1Group)
		{
			unionSection.insert(i);
			auto retval = str2Group.find(i);
			if (retval != str2Group.end())
			{
				interSection.insert(i);
				str2Group.erase(retval);
			}
		}
		for (const auto& i : str2Group)
			unionSection.insert(i);
		
		answer = (double)interSection.size() / (double)unionSection.size();
	}
	return answer * 65536;
}

int main()
{
	//cout << solution("FRANCE", "french");
	cout << solution("aa1+aa2", "AAAA12");
	return 0;
}