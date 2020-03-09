 //https://www.acmicpc.net/problem/4963

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

vector<vector<int>> adj;
vector<vector<bool>> visited;

int dy[8] = { 1,1,1,0,0,-1,-1,-1 };
int dx[8] = { -1,0,1,-1,1,-1,0,1 };
int w,h;

void dfs(int y, int x)
{
	visited[y][x] = true;

	for (int i = 0; i < 8; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= h || nx >= w)
			continue;

		if (adj[ny][nx] && !visited[ny][nx])
			dfs(ny, nx);
	}
}

void solution()
{
	int ret = 0;

	for (int y = 0; y < h; ++y)
		for (int x = 0; x < w; ++x)
			if (!visited[y][x] && adj[y][x])
			{
				ret++;
				dfs(y, x);
			}
		
	cout << ret << '\n';
}


int main()
{
	

	while (1)
	{
		cin >> w >> h;
		if (w == 0 && h == 0)
			break;

		visited = vector < vector<bool>>(h, vector<bool>(w, 0));
		adj = vector < vector<int>>(h, vector<int>(w, 0));

		for (int i = 0; i < h; ++i)
			for (int j = 0; j < w; ++j)
				cin >> adj[i][j];

		solution();

	}
		
	return 0;
}
