//https://programmers.co.kr/learn/courses/30/lessons/43163
#include <string>
#include <vector>
#include <iostream>

using namespace std;
#define MAX 987654321

int dfs(int node,int now, const string & target , vector<vector<bool>> & v, vector<bool>& visited , const vector<string>& words)
{
	if (target == words[node])
	{
		return now;
	}
	int ret = MAX;
	for (int i = 0; i < v[node].size(); ++i)
	{
		if (visited[i])
			continue;
		if (!v[node][i])
			continue;

		visited[i] = true;
		int tmp = dfs(i, now + 1, target, v, visited,words);
		visited[i] = false;

		if (ret > tmp)
			ret = tmp;
	}

	return ret;

}
int solution(string begin, string target, vector<string> words) {
	
	int answer = MAX;
	words.push_back(begin);
	int size = words.size();
	bool available = false;

	vector<vector<bool>> v(words.size(), vector<bool>(words.size(), false));
	vector<bool>visited(words.size(), false);
	for (int i = 0; i < words.size(); ++i)
	{
		string alpha = words[i];

		if (alpha == target)
			available = true;
		for (int j = 0; j < words.size(); ++j)
		{
			if (i == j)
				continue;

			int diff = 0;
			string beta = words[j];
			for (int i = 0; i < beta.length(); ++i)
			{
				if (alpha[i] != beta[i])
					diff++;
			}
			
			if (diff == 1)
				v[i][j] = v[j][i] = true;
		}
	}

	if (!available)
		return 0;
	visited[size - 1] = true;
	answer = dfs(words.size() - 1,0,target, v, visited, words);

	return answer;
}
