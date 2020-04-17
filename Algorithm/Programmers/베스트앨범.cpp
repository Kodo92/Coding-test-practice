#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool comp(pair<int,int> _A, pair<int, int> _B)
{
	return _A.first > _B.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;

	map<string, int> genreScores;
	map<int, string> genreRanking;
	map<string, vector<pair<int, int>>> musicScores;

	for (int i = 0; i < genres.size(); i++)
	{
		auto retVal = genreScores.insert(make_pair(genres[i], plays[i]));
		if (retVal.second == false)
			genreScores[genres[i]] += plays[i];
		musicScores[genres[i]].push_back(make_pair(plays[i], i));
	}

	vector<pair<string, int>> genreRanking(genreScores.begin(), genreScores.end());
	sort(genreRanking.begin(), genreRanking.end(), comp);

	for(auto& i : musicScores)
		sort(i.second.begin(), i.second.end(),comp);

	int loopCount = 0;
	for (auto i = genreRanking.rbegin() ; i != genreRanking.rend() ; i++)
	{
		loopCount = 0;
		string Genere = i->second;
		for (auto j = musicScores[Genere].begin(); j != musicScores[Genere].end(); j++)
		{
			answer.push_back(j->second);
			loopCount++;
			if (loopCount == 2) break;
		}

	}

	return answer;
}

void main()
{
	map<string, map<int, vector<int>>> bestAlbum;
	bestAlbum["pop"][500].push_back(0);
	bestAlbum["classic"][700].push_back(1);
	bestAlbum["classic"][700].push_back(4);
	bestAlbum["classic"][500].push_back(4);
	
	solution({ "classic","pop","classic" ,"classic","pop" }, { 500,600,800,800,400 });
	cout << endl;
}