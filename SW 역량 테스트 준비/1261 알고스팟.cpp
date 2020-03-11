//https://www.acmicpc.net/problem/1261

#include <iostream>
#include <deque>
#include <vector>
#include <stdio.h>

using namespace std;

vector< vector<bool>> visited;
vector< vector<int >> adj;
int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,-1,1 };

void bfs(int n, int m)
{
	deque<pair<int,int>> q;
	q.push_front(make_pair(0, 0));
	visited[0][0] = true;

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop_front();

		if (y + 1 == n && x + 1 == m)
		{
			cout << adj[y][x] << '\n';

			/*for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < m; ++j)
					cout << adj[i][j] << " ";
				cout << '\n';
			}*/
			return;
		}


		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;

			if (!visited[ny][nx])
			{
				if (!adj[ny][nx])	//빈방
				{
					visited[ny][nx] = true;
					q.push_front(make_pair(ny, nx));
					adj[ny][nx] = adj[y][x];
				}
				else//벽방
				{
					visited[ny][nx] = true;
					q.push_back(make_pair(ny, nx));
					adj[ny][nx] = adj[y][x]+1;
				}
			}

		}

	}

	return;
}

int main()
{
	int m, n;
	cin >> m >> n;

	adj = vector<vector<int>>(n, vector<int>(m, 0));
	visited  = vector<vector<bool>>(n, vector<bool>(m, 0));

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			scanf("%1d", &adj[i][j]);
			//scanf_s("%1d", &adj[i][j]);

	bfs(n, m);
}
