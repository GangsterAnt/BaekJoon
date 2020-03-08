//https://www.acmicpc.net/problem/1260

#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

vector < vector<int> > adj;
vector<int> path;
queue<int> myq;
bool visited[1001];


void bfs(const vector<vector<int>> &adj, int vertex_num, int start)
{
	myq.push(start);
	visited[start] = true;

	while ( !myq.empty())
	{
		int temp = myq.front();
		myq.pop();
		cout << temp << " ";
		for (int i = 1; i <= vertex_num; ++i)
		{
			if (!visited[i])
			{
				if (adj[temp][i] || adj[i][temp])
				{
					visited[i] = true; 
					path.push_back(i);
					myq.push(i);
				}
			}
		}
	}

	cout << '\n';

}
void dfs(const vector<vector<int>> &adj, int depth, int now, int start)
{
	/*if (depth == now)
	{
		for (int i = 0; i < path.size(); ++i)
			cout << path[i] << " ";
		cout << '\n';
		return;
	}*/

	visited[start] = true;
	cout << start << " ";

	for (int i = 0; i < adj.size(); ++i)
	{
		if (!visited[i])
		{
			if (adj[start][i] || adj[i][start])
			{
				dfs(adj, depth, now + 1, i);
			}
		}
	}
	

	
}

int main()
{
	int n, m, v;
	cin >> n >> m >> v;

	adj = vector < vector<int>> (n+1, vector<int>(n+1, 0));
	for (int i = 0; i < m; ++i)
	{
		int y, x;
		cin >> y >> x;
		adj[y][x] = 1;
	}

	dfs(adj, n, 0, v);
	cout << '\n';
	memset(visited, false, sizeof(visited));
	path.clear();

	bfs(adj,n, v);

	return 0;
}
