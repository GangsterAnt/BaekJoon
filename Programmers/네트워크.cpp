//https://programmers.co.kr/learn/courses/30/lessons/43162
#include <string>
#include <vector>

using namespace std;

vector<bool> visited;

void dfs(int node ,const vector<vector<int>>& computers)
{
	if (visited[node])
		return;
	
	visited[node] = true;
	for (int i = 0; i < computers.size(); ++i)
	{
		if (node == i)
			continue;

		if (computers[node][i] == 1 && visited[i] == false)
			dfs(i, computers);
			
	}
}


int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	int size = computers.size();
	visited = vector<bool>(computers.size(), false);

	for (int i = 0; i < size; ++i)
	{
		if (visited[i])
			continue;
		else
		{
			answer++;
			dfs(i, computers);
		}
	}

	return answer;
}
