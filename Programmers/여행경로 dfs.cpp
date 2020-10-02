//https://programmers.co.kr/learn/courses/30/lessons/43164

#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

map<string, int> m;

vector<string> dfs(int start, int depth, vector<string> &ans, const vector<vector<string>>& tick, vector<vector<bool>>& visited)
{
	//start 는 시작 index

	if (ans.size() == depth)
	{
		return ans;
	}

	vector<string> ret;
	for (int i = 0; i < tick[start].size(); ++i)
	{
		if (visited[start][i])
			continue;

		if (m.find(tick[start][i]) == m.end() && ans.size() != depth - 1)
			continue;

		visited[start][i] = true;
		ans.push_back(tick[start][i]);




		auto tmp = dfs(m[tick[start][i]], depth, ans, tick, visited);

		if (tmp.size() == depth)
			return tmp;


		visited[start][i] = false;
		ans.pop_back();

	}

	return ret;
}

bool cmp(string a, string b)
{
	return a < b;
}
vector<string> solution(vector<vector<string>> tickets) {
	vector<string> answer;

	vector<vector<string>> tick;
	vector<vector<bool>> visited;
	vector<string> depart;

	int ICN;

	//티켓 전처리
	for (int i = 0; i < tickets.size(); ++i)
	{
		string src = tickets[i][0];
		string dest = tickets[i][1];

		if (m.find(src) == m.end())
		{
			m[src] = depart.size();
			depart.push_back(src);

			vector<string> tmp;
			tmp.push_back(dest);
			tick.push_back(tmp);

			vector<bool> tmp2;
			tmp2.push_back(false);
			visited.push_back(tmp2);
		}
		else
		{
			int index = m[src];
			tick[index].push_back(dest);
			bool tmp = false;
			visited[index].push_back(tmp);
		}

	}

	ICN = m["ICN"];

	for (int i = 0; i < tick.size(); ++i)
		sort(tick[i].begin(), tick[i].end(), cmp);

	for (int i = 0; i < tick.size(); ++i)
	{
		cout << "Start : " << depart[i] << '\n';
		for (int j = 0; j < tick[i].size(); ++j)
		{
			cout << tick[i][j] << ' ';
		}
		cout << '\n';
	}

	answer.push_back("ICN");
	answer = dfs(ICN, tickets.size() + 1, answer, tick, visited);

	return answer;
}
