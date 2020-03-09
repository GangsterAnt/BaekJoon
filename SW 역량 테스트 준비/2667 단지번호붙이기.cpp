//https://www.acmicpc.net/problem/2667

#include <iostream>
#include <vector>
#include <algorithm>
#include<stdio.h>

using namespace std;

int dy[4] = { 1, 0 , 0 ,-1 };
int dx[4] = { 0,-1,1,0 };	//상하좌우

int n;
vector<int> area;
vector < vector<int>> adj;
vector < vector<bool>> visited;

int dfs(int y, int x)
{
	int ret = 1;	//일단 호출 되면 y x 의 넓이만큼은 반드시 추가된다 ( 호출 == 면적 +1)
	visited[y][x] = 1;
	
	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= n || nx < 0 || nx >= n)	// 좌표 유효성 체크
			continue;

		if (adj[ny][nx]&& !visited[ny][nx])	// 집이 있고 (adj) 방문x시 (!visited)
		{
			//cout << "Calling dfs( " << ny << " " << nx << " ) \n";
			ret += dfs(ny, nx);		//호출
		}

	}
	
	return ret;
}

void solution()
{
	int temp;
	for(int y=0; y<n; ++y)
		for (int x=0; x < n; ++x)
		{
			if (adj[y][x] && !visited[y][x])
			{
				//cout << "Calling dfs( " << y << " " << x << " ) \n";
				temp = dfs(y, x);
				area.push_back(temp);
			}
		}

	sort(area.begin(), area.end());
	cout << area.size()<<'\n';	//단지의 개수

	for (int i = 0; i < area.size(); ++i)
		cout << area[i]<<'\n';
}


int main()
{
	
	cin >> n;


	adj = vector< vector<int>>(n, vector<int>(n, 0));
	visited = vector< vector<bool>>(n, vector<bool>(n, 0));

	for (int y = 0; y < n; ++y)
		for (int x = 0; x < n; ++x)
			scanf("%1d", &adj[y][x]);	//for online Judgement
			//scanf_s("%1d", &adj[y][x]); visual studio
			
	//cout << "Insert Is Done! \n";
	solution();

	return 0;
}
