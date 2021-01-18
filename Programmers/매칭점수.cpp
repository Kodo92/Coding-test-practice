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
	double originCount = 0.0f;		// �⺻����
	double linkCount = 0.0f;		// ��ũ����
	double totalScore = 0.0f;		// ���� ����
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

	// �� ������ �̸� ������, �ε��� ���� : indexs
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

	// �������� �⺻ ������ �ܺ� ��ũ ���� ��� �� �ܺ� ��ũ ���� �迭�� ���� (���� ���� �ʴ� �ܺθ�ũ�� ��� ����)
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
