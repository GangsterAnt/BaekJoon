//https://www.acmicpc.net/problem/11724

#include<iostream>
#include<vector>
#include<queue>

using namespace std;
bool visited[1001];
int num = 0;


void dfs(const vector<vector<int>> &adj ,int depth, int start)
{
	/*if (depth == now)
	{
		return;
	}*/

	visited[start] = true;

	for (int i = 1; i <= depth; ++i) 
	{
		if (!visited[i])
		{
			if (adj[start][i] || adj[i][start])
			{
				dfs(adj, depth, i);
			}
		}
	}
}

int solution(const vector<vector<int>> &adj, int depth)
{
	int result = 0;
	
	for (int i = 1; i <= depth; ++i)
	{
		if (!visited[i])
		{
			result++;
			//cout << i << " Is not visited! Result : " << result << '\n';
			dfs(adj, depth, i);
		}
		else
			continue;
	}

	return result;
	
}
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;

	vector< vector<int>> adj = vector< vector<int>> (n + 1, (vector<int>( n + 1, 0) ) );

	for (int i = 0; i < m; ++i)
	{
		int y, x;
		cin >> y >> x;
		adj[y][x] = adj[x][y] = 1;
	}

	/*for (int i = 1; i < adj.size(); ++i)
	{
		for (int j = 1; j < adj.size(); ++j)
			cout << adj[j][i] << " ";
		cout << '\n';
	}*/
	cout << solution(adj,n) << '\n';

	return 0;
}
