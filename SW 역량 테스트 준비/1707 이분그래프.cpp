//https://www.acmicpc.net/problem/1707

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int visited[20001];
bool fin = 1;

void dfs(const vector<vector<int>>& adj, int depth, int start,int color)
{
	visited[start] = color;

	for (int i = 0; i < adj[start].size(); ++i)	// i 는 start의 간선들의 번호
	{
		int next = adj[start][i];	//next 는 vertex 번호

		if (visited[next] == 0)
		{
			//방문하지 않았다면 컬러값을 주고 dfs 호출
			dfs(adj, depth, next, 3 - color);	//1 ->2 2	
		}
		else if (color == visited[next]) //이어져있는 정점끼리 컬러가 같다면...
		{
			//cout << start << " " << next << "Is Wrong!!\n";
			fin = 0;
			return;						//더 볼것이 없다 종료
		}
		
	}
}

void solution(const vector< vector<int>>& adj, int depth)
{
	fin = 1;//초기화

	for (int i = 1; i <= depth; ++i)
	{
		if(!visited[i])
			dfs(adj, depth, i, 1);
	}

	for (int i = 1; i <= depth; ++i)
	{
		if (visited[i] == 0)
		{
			//cout << i << " Is Wrong!!\n";
			fin = 0;
			break;
		}
	}

	if (fin)
		cout << "YES\n";
	
	else
		cout << "NO\n";

	 
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector < vector< int>> adj;

	int c, v, e;
	cin >> c;
	while (c--) 
	{
		cin >> v >> e;
		adj = vector< vector<int>>(v + 1, vector<int>(0));

		for (int i= 0; i < e; ++i)
		{
			int x, y;
			cin >> y >> x;
			adj[y].push_back(x);
			adj[x].push_back(y);
		}

		/*for (int i = 1; i <= v; ++i)
		{
			cout << "Index " << i << " : ";
			for (int j = 0; j < adj[i].size(); ++j)
				cout << adj[i][j] << " ";
			cout << '\n';
		}*/
		if (e == 0 || v == 0)
		{
			cout << "NO\n";
		}
		else
		{
			solution(adj, v);
			adj.clear();
			memset(visited, 0, sizeof(visited));
		}
		
	}
	return 0;
}
