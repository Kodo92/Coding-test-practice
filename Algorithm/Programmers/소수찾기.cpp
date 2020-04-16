#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

vector<char> numberVector;
set<int> primeNumbers;

bool checkPrimeNumber(int _Number)
{
	if (_Number <= 1) return false;
	if (_Number == 2 || _Number == 3) return true;
	if (_Number % 2 != 0 && _Number % 3 != 0) return true;
	return false;
}

int combinationNumber(int _Depth, string _String, int _numberPos)
{
	if (_Depth == 0) return 0;

	int answer = 0, primeNumber =0;
	for (int i = 0; i < numberVector.size(); i++)
	{
		if (i == _numberPos) continue;
		string newString = _String + numberVector[i];
		primeNumber = stoi(newString);
		if (checkPrimeNumber(primeNumber))
			primeNumbers.insert(primeNumber);
		combinationNumber(_Depth - 1, newString, i);
	}
}

int solution(string numbers) {
	
	for (int i = 0; i<numbers.size(); i++)
		numberVector.push_back(numbers[i]);
	combinationNumber(numberVector.size(), "", -1);
	return primeNumbers.size();
}

void main()
{

	cout << solution("011");
}