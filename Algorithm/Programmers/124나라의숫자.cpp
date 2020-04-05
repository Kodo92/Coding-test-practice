#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int n) {
	string answer = "";
	vector<long long> caledValue;
	int Quotient = 0, Remainder = 0;
	Quotient = n / 3;
	Remainder = n % 3;
	if (Remainder == 0)
		Quotient--;
	caledValue.push_back(Remainder);
	
	while (Quotient >= 3)
	{
		Remainder = Quotient % 3;
		Quotient = Quotient / 3;
		if (Remainder == 0)
			Quotient--;
		caledValue.push_back(Remainder);
	}
	if(Quotient != 0)
		caledValue.push_back(Quotient);

	while (!caledValue.empty())
	{
		switch (caledValue.back())
		{
		case 0:
			answer += to_string(4);
			break;
		case 1:
			answer += to_string(1);
			break;
		case 2:
			answer += to_string(2);
			break;
		default:
			break;
		}
		caledValue.pop_back();
	}
	return answer;
}

int main()
{
	cout << solution(40);

	return 0;
}