https://programmers.co.kr/learn/courses/30/lessons/42579

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include<tuple>

using namespace std;
int n;
map<string, int>m;
vector<tuple<string, int, int>>t;

bool cmp(tuple<string, int, int> a, tuple<string, int, int> b)
{
	if (m[get<0>(a)] != m[get<0>(b)] )
	{
		return m[get<0>(a)] > m[get<0>(b)];
	}

	if (get<1>(a) != get<1>(b))
		return get<1>(a) > get<1>(b);

	return get<2>(a) < get<2>(b);
}

bool cmp2(pair<int, int>a, pair<int, int> b)
{
	return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	
	vector<int> answer;
	int g_size = 0;
	vector<string>g;
	n = genres.size();



	for (int i = 0; i < n; ++i)
	{
		if (m[genres[i]] == 0)
		{
			g.push_back(genres[i]);
			g_size++;
		}

		m[genres[i]] += plays[i];
	}
	//각 장르별 순위 매기기용 벡터 v를 만든다.
	vector< vector<pair<int, int>>> v = vector<vector<pair<int, int>>>(g_size);
	
	for (int i = 0; i <n; ++i)
	{
		//j는 장르의 인덱스, i는 하나의 곡에 대한 인덱스
		for (int j = 0; j < g_size; ++j)
		{
			//곡 i의 장르가 j 라면
			if (genres[i] == g[j])
			{
				v[j].push_back(make_pair(plays[i], i));
			}
		}
	}

	for (int j = 0; j < g_size; ++j)
		sort(v[j].begin(), v[j].end(), cmp2);
	
	for (int j = 0; j < g_size; ++j)
	{
		t.push_back(make_tuple(g[j], v[j][0].first, v[j][0].second));
		if( v[j].size() >= 2)
			t.push_back(make_tuple(g[j], v[j][1].first, v[j][1].second));
		//t.push_back(make_tuple(genres[i], plays[i], i));
	}
	

	sort(t.begin(), t.end(), cmp);

	for (int i = 0; i < t.size(); ++i)
		answer.push_back( get<2>(t[i]));
	

	return answer;
}
