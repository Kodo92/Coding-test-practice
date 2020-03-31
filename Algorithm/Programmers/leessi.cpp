#include <iostream>
#include <string>
#include<vector>
using namespace std;

// 채점 결과 1ms 넘어가는 케이스 다수
int Checking(const int _Unit, const string s)
{
	int stringSize = s.size();
	string comparedString = "";
	string answerString = "";

	vector<string> dividedStrings;

	for (int i = 0; i < stringSize; i += _Unit)
		dividedStrings.push_back(s.substr(i, _Unit));

	int compareCount = 0, loopPos = 0;
	for (int j = 0; j < dividedStrings.size();)
	{
		comparedString = dividedStrings[j];
		compareCount = 1;
		for (loopPos = j+1;  loopPos < dividedStrings.size(); loopPos++)
		{
			if (comparedString == dividedStrings[loopPos])
				compareCount++;
			else
				break;
		}
		if (compareCount > 1)
			answerString += to_string(compareCount);
			
		answerString += comparedString;
		j = loopPos;
			
	}
	cout << answerString << endl;
	return answerString.size();
}

// 채점 결과 최대 0.95ms
int compareChecking(int _Unit, const string _String)
{
	int comparedResult = 1;
	int ownerCount = 0, subCount = 0, stringSize = _String.size();
	string answerString ="";

	for (ownerCount; ownerCount < stringSize; )
	{
		for (subCount = ownerCount + _Unit; subCount < stringSize; subCount+= _Unit)
		{
			int retVal = _String.compare(ownerCount, _Unit, _String, subCount, _Unit);
			if (retVal == 0) comparedResult++;
			else break;
		}
		if (comparedResult > 1)
			answerString += to_string(comparedResult);
		answerString += _String.substr(ownerCount, _Unit);
		ownerCount = subCount;
		comparedResult = 1;
	}

	return answerString.size();
}

// Max processing time : 0.14ms
int comapreCheckingNumberVer(int _Unit, const string _String)
{
	int comparedResult = 1;
	int answerCount = 0;
	int ownerCount = 0, subCount = 0, stringSize = _String.size();

	for (ownerCount; ownerCount < stringSize; )
	{
		for (subCount = ownerCount + _Unit; subCount < stringSize; subCount += _Unit)
		{
			int retVal = _String.compare(ownerCount, _Unit, _String, subCount, _Unit);
			if (retVal == 0) comparedResult++;
			else break;
		}
		if (comparedResult > 1)
			answerCount += to_string(comparedResult).size();
		if (stringSize - ownerCount < _Unit)
			answerCount += stringSize - ownerCount;
		else
			answerCount += _Unit;
		ownerCount = subCount;
		comparedResult = 1;
	}

	return answerCount;
}


int solution(string s)
{
	int answer = s.size(), retVal = s.size();
	int endCount = (s.size() / 2)+1;
	for (int i = 1; i < endCount; i++)
	{
		retVal = comapreCheckingNumberVer(i,s);
		if (retVal < answer)
			answer = retVal;
	}
	return answer;
}

int main()
{
	
	cout << solution("aabcccccccc");


	return 0;
}