//https://www.acmicpc.net/problem/2178

#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>

using namespace std;

vector< vector<int>> adj;
vector <vector <bool>> visited;

int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,-1,1 };


void bfs(int h, int w)
{
	queue< pair<int, int>> q;
	q.push(make_pair(0, 0));
	
	visited[0][0] = true;

	while (!q.empty())
	{
		int temp_y = q.front().first;
		int temp_x = q.front().second;

		
		q.pop();
		
		if (temp_y + 1 == h && temp_x + 1 == w)	//종료조건
		{
			cout << adj[temp_y][temp_x] << '\n';
			break;
		}
		

		for (int i = 0; i < 4; ++i)
		{
			int ny = temp_y + dy[i];
			int nx = temp_x + dx[i];

			if (ny < 0 || nx < 0 || ny >= h || nx >= w)		//좌표 유효성 체크
				continue;

			if (!visited[ny][nx] && adj[ny][nx])	//방문체크와 길인지 체크
			{
				visited[ny][nx] = true;		// 이거 여기서 안하면 메모리 초과!!!
											
				q.push(make_pair(ny, nx));
				adj[ny][nx] = adj[temp_y][temp_x] + 1;
			}

		}
		

	}

	return;
}

int main()
{

	int h, w;
	cin >> h >> w;

	adj = vector<vector<int>>(h, vector<int>(w, 0));
	visited = vector<vector<bool>>(h, vector<bool>(w, 0));

	for (int y = 0; y < h; ++y)
		for (int x = 0; x < w; ++x)
			//scanf("%1d", &adj[y][x]);	//for online Judgement
			scanf_s("%1d", &adj[y][x]); //visual studio

	bfs(h,w);

	return 0;
}
