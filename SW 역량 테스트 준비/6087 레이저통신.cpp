//https://www.acmicpc.net/problem/6087
//https://code.plus/lecture/347

#include <iostream>
#include <vector>
#include <queue>
#include<deque>
#include <algorithm>

int dy[] = { -1,0,1,0 }; //상 우 하 좌 
int dx[] = { 0,1,0,-1 };//각 인접 index 들은 진행방향으로 했음  i+1 %4 i-1 (i+3) %4 는 진행가능방향
using namespace std;
int bfs(vector<vector<char>>&v, vector<pair<int, int>>& laser)
{
	int start_y = laser[0].first;
	int start_x = laser[0].second;

	int size_y = v.size();
	int size_x = v[0].size();

	int done_y = laser[1].first;
	int done_x = laser[1].second;

	vector<vector<int>> direction(size_y, vector<int>(size_x, -1));
	vector<vector<int>> curve(size_y, vector<int>(size_x, -1));
	queue<pair<int, int> > q;

	q.push(laser[0]);
	curve[start_y][start_x] = 0;
	direction[start_y][start_x] = 5;
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		if (y == done_y && x == done_x)
		{
			/*for (int i = 0; i < size_y; ++i)
			{
				for (int j = 0; j < size_x; ++j)
				{
					cout << curve[i][j] << ' ';
				}cout << '\n';
			}
			cout << '\n';
			for (int i = 0; i < size_y; ++i)
			{
				for (int j = 0; j < size_x; ++j)
				{
					cout << direction[i][j] << ' ';
				}cout << '\n';
			}*/

			return curve[y][x];
		}



		for (int i = 0; i < 4; ++i) //진행은 항상 3방향이지만.. 일반성을 위해
		{	//상 우 하 좌 


			int ny = y + dy[i]; int nx = x + dx[i];

			while (1)
			{
				if (ny < 0 || nx < 0 || ny >= size_y || nx >= size_x)
					break;	//유효값 처리
				/*if (direction[ny][nx] != -1)
						break;
				위 조건식을 추가하면 오답이 된다.
				단순한 방문 처리 같지만 , 각 좌표값이 큐에 들어가는 순서를 생각해보자.
				4 4			
				C.**	이 왼쪽의 예제에서 큐에 상우하좌 순서로 들어가므로
				..**	 3,2는 curve 가 1 이 아닌 2를 갖는다.
				....	즉 curve의 변화를 보면..
				...C

				0 0-1-1		0 0-1-1 이 된다  이떄 3,0 이 오른쪽으로 진행하려 하지만,
				0-1-1-1		0 1-1-1 3,1이 이미 0,1에 의해 큐에 집어넣어졌고 방문처리가 되어있기때문에
				0-1-1-1		0 1-1-1	3,1은 3,2를 업데이트 하지 못한다. 이런식으로 최단거리를 만들지 못하게되므로
				0-1-1-1		0 1-1-1  if (direction[ny][nx] != -1) 가 아닌 if (direction[ny][nx] == -1) 일경우 bfs 를 수행해야한다.
				*/
				if (v[ny][nx] == '*')
					break;	//벽 처리
				if (direction[ny][nx] == -1)
				{
					q.push(make_pair(ny, nx));
					direction[ny][nx] = i;

					if (direction[y][x] == 5 || direction[y][x] == i)	//방향이 같은경우
						curve[ny][nx] = curve[y][x];
					else
						curve[ny][nx] = curve[y][x] + 1;
				}
				ny += dy[i]; nx += dx[i];
			}
		}


		
	}
	return -1; 
}
int main()
{
	int w, h;
	cin >> w >> h;
	vector<pair<int, int>> laser;
	vector<vector<char>> v(h, vector<char>(w, '.'));

	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j)
		{
			cin >> v[i][j];
			if (v[i][j] == 'C')
				laser.push_back(make_pair(i, j));
		}

	/*for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			cout << v[i][j] << ' ';
		}cout << '\n';
	}*/
	cout << bfs(v, laser) << '\n';


	return 0;
}
