//https://www.acmicpc.net/problem/10971

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int result_min = 99999999;
vector<int> path;


void dfs(const vector<vector<int>> & adj, vector <bool> & visited, int now, int depth, int here)
{
	if (depth == now)
	{
		if (adj[path.back()][path.front()] == 0)	//마지막 v 에서 root로 못간다면 X
			return;

		int cal = 0;
		path.push_back(path[0]);
		for (int i = 1; i < path.size(); ++i)
			cal += adj[path[i - 1]][path[i]];
		
		/*for (int i = 0; i < path.size(); ++i)
			cout << path[i] << " ";
		cout << "And .. Result Cal : " << cal << '\n';*/
		path.pop_back();
		result_min = min(result_min, cal);
	}

	if (!visited[here] )
	{
		visited[here] = true;
		path.push_back(here);

		for (int there = 0; there < adj.size(); ++there)
		{
			if(adj[here][there] !=0)
				dfs(adj, visited, now + 1, depth, there);
		}
		visited[here] = false;
		path.pop_back();
	}
}
void Graph(const vector<vector<int>> & adj, vector <bool> & visited, int now, int depth)
{
	
	for (int here = 0; here < depth; ++here)
	{
		dfs(adj, visited, now, depth, here);
	}
	
}

int main()
{
	int c;
	cin >> c;

	vector< vector < int> > adj = vector < vector <int>> ( c, vector<int>(c,0));
	vector < bool>  visited  = vector<bool>(c, false);

	for (int y = 0; y < c; ++y)
		for (int x = 0; x < c; ++x)
			cin >> adj[y][x];

	Graph(adj, visited,0, c);
	cout << result_min << '\n';

	return 0;
}
