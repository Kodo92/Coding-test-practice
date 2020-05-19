#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class scoreData
{
public:
	vector<string> links;

private:
	double originCount = 0.0f;		// 기본점수
	double linkCount = 0.0f;		// 링크점수
	double totalScore = 0.0f;		// 최종 점수
public:
	scoreData() {};
	double	getScore() const { return originCount / linkCount; }
	void		addLinkScore() { linkCount++; }
	void		addOriginScore() { originCount++; }
	void		addTotalScore(const float value) { totalScore += value; }
	double	getTotalScore() const  { return totalScore + originCount; }
};

int solution(string word, vector<string> pages) {

	map<string, int> indexs;
	vector<scoreData> datas (pages.size());

	transform(word.begin(), word.end(), word.begin(), ::toupper);

	// 웹 페이지 이름 얻어오고, 인덱스 저장 : indexs
	for (int i = 0; i < pages.size(); i++)
	{
		auto& value = pages[i];
		transform(value.begin(), value.end(), value.begin(), ::toupper);
		auto start = value.find("<META PROPERTY=\"OG:URL\" CONTENT=");
		start += 33;
		auto end = value.find("/>", start);
		string content = value.substr(start, (end - start - 1));
		indexs[content] = i;
	}

	// 웹페이지 기본 점수와 외부 링크 점수 계산 및 외부 링크 정보 배열에 저장 (존재 하지 않는 외부링크인 경우 생략)
	for(int i=0;i<pages.size();i++)
	{
		auto& value = pages[i];
		size_t start = 0, end = 0;

		while (start = value.find(word, start))
		{
			if (start == string::npos)
				break;

			if (!isalpha(value[start - 1]) && !isalpha(value[start + word.size()]))
				datas[i].addOriginScore();
			start++;
		}
		start = 0;

		while (start = value.find("<A HREF=", start))
		{
			if (start == string::npos)
				break;
			start += 9;
			end = value.find("\">", start);
			string url = value.substr(start, end - start);
			datas[i].addLinkScore();
			datas[i].links.push_back(value.substr(start, end-start));
		}
	}

	for (const auto& value : datas)
	{
		double linkScore = value.getScore();
		for (const auto& secondValue : value.links)
		{
			const auto& retval = indexs.find(secondValue);
			if (retval == indexs.end())
				continue;
			datas[indexs[secondValue]].addTotalScore(linkScore);
		}
	}

	double max = 0;
	int answer = 0;
	for (int i= 0;i<datas.size();i++)
	{
		const auto& value = datas[i];
		double retval = value.getTotalScore();
		if (max < retval)
		{
			max = retval;
			answer = i;
		}
	}
	return answer;
}
