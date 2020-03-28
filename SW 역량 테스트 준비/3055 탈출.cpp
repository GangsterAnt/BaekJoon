//https://www.acmicpc.net/problem/3055

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector <vector <char>> adj;
vector <vector <int>> visited;
vector <vector <int>> water;

int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,-1,1 };


void flood(int r, int c)
{
	queue<pair< int,int>> q;

	for(int y=0;y<r;++y)
		for (int x = 0; x < c; ++x)
			if (adj[y][x] == '*')
			{
				water[y][x] = 0;
				q.push(make_pair(y, x));
			}

	while (!q.empty())
	{
		int temp_y = q.front().first;
		int temp_x = q.front().second;

		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int ny = temp_y + dy[i];
			int nx = temp_x + dx[i];

			if (ny < 0 || nx < 0 || ny >= r || nx >= c)
				continue;
			if (adj[ny][nx] == 'X' || adj[ny][nx] == 'D')	//침수 불가능 지역
				continue;
			if (water[ny][nx] == -1)	// != -1 은 이미 방문 되었다는 뜻 
			{
				water[ny][nx] = water[temp_y][temp_x] + 1;
				q.push(make_pair(ny, nx));
			}
		}
	}

}

void bfs(int r, int c, pair<int,int> start, pair<int,int> end)
{
	
	int y = start.first;
	int x = start.second;
	
	int end_y = end.first;
	int end_x = end.second;

	queue< pair<int, int>> q;
	visited[y][x] = 0;
	q.push(make_pair(y, x));

	while (!q.empty())
	{
		int temp_y = q.front().first;
		int temp_x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int ny = temp_y + dy[i];
			int nx = temp_x + dx[i];

			if (ny < 0 || nx < 0 || ny >= r || nx >= c)
				continue;

			if (visited[ny][nx] != -1)
				continue;

			if (adj[ny][nx] == 'X') //예외조건 : 돌
				continue;
			if (water[ny][nx] != -1 && visited[temp_y][temp_x] + 1 >= water[ny][nx])
				//물이 차는 지역이여야 하고 ( water[ny][nx] != -1 없을시.. visited[][] ==-1 이랑 꼬일수도
				// 최단거리가 물이 차는 시간 "미만"이어야 한다 " 둘이 같은 시간이 걸릴경우.. 물이 차는곳으로 이동하는것이다.
				continue;

			visited[ny][nx] = visited[temp_y][temp_x]+1;
			q.push(make_pair(ny, nx));
			
		}

	}
	//큐가 빌때까지 종료 X 불가능
	if (visited[end_y][end_x] == -1)
		cout << "KAKTUS\n";
	else
		cout << visited[end_y][end_x] << '\n';
	return;
}
int main()
{
	
	int r, c;
	pair<int, int> start, end;
	cin >> r >> c;
	
	adj		= vector< vector<char>>(r, vector<char>(c, 0));
	visited = vector< vector<int>>(r, vector<int>(c, -1));
	water	= vector< vector<int>>(r, vector<int>(c, -1));

	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
		{
			cin >> adj[i][j];
			if (adj[i][j] == 'S')
				start = make_pair(i, j);
			else if (adj[i][j] == 'D')
				end = make_pair(i, j);
		}

	flood(r, c);
	bfs(r, c,start,end);
	return 0;
}
