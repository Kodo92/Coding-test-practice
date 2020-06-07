#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int min;
std::vector<std::set<int>> vec;

void cal(const int N, const int number, const int count)
{
	// min 보다 count가 크면 무의미한 탐색이다.
	if (count > min || count > 7)	return;	

	/*
		- 사칙연산 결과는 음수 & 0이 나오면 안된다. 
			A. 0이 나올 수 있는 경우 : -, /
			B. 음수가 나올 수 있는 경우 : -

		- N을 i번 사용하는 경우 조합 방법
			A. 두 정수를 더했을 때 i가 나오면 된다. 
			B. 이미 사칙연산한 조합은 값이 중복되므로 생략한다.
				1. (0,1), (1,0)은 중복이다. 하지만 - 와 / 연산은 주의가 필요하다. 
				2. (0,1)에서 - 연산의 음수의 절댓값은 (1,0)의 - 연산과 같다.
				3. (0,1)에서 / 연산의 결과가 0 이라면 (1,0)의 / 연산으로 대체한다.
	*/
	for (int i = 0; i < (count + 1) / 2; i++)		
	{
		int j = count - (i + 1);			// ex) count 3이고 i = 0이면 2와 사칙연산을 실행해야하므로 2를 구한다.
		for (const auto value : vec[i])
		{
			for (const auto secondValue : vec[j])
			{
				vec[count].insert(value + secondValue);
				if(value - secondValue != 0)
					vec[count].insert(abs(value - secondValue));		
				vec[count].insert(value * secondValue);
				vec[count].insert((value > secondValue) ? value / secondValue : secondValue/value);				
			}
		}
	}

	if (vec[count].count(number) != 0)
		min = std::min(min, count);
}

int solution(int N, int number) {
	min = 8;			
	vec.resize(8);

	// N을 i+1개 사용하는 경우 계산
	int temp = N;
	for (int i = 0; i < 8; i++, temp = (temp*10)+N)
	{
		vec[i].insert(temp);		// N을 i+1개 사용하는 경우 ex) 5, 55, 555 ~
		cal(N, number, i);
	}

	return (min == 8) ? -1 : min+1;
}

/*
참고 사이트 : 
https://gurumee92.tistory.com/164

*/