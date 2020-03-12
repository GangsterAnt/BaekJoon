//https://www.acmicpc.net/problem/3055

#include <iostream>
#include <queue>
#include <vector>

using namespace std;


int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,-1,1 };

vector <vector <char>> adj;
vector<vector <int>> visited;
vector<vector <int>> water;

void flood(int r, int c)
{
	queue< pair<int, int>> q;

	for (int y = 0; y < r; ++y)
	{
		for (int x = 0; x < c; ++x)
		{
			if (adj[y][x] == '*')
			{
				water[y][x] = 0;
				q.push(make_pair(y, x));
			}

		}
	}

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;

		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= r || nx >= c)
				continue;

			if (water[ny][nx] != -1)
				continue;
			if (adj[ny][nx] == 'X')
				continue;
			if (adj[ny][nx] == 'D')
				continue;

			water[ny][nx] = water[y][x] + 1;
			q.push(make_pair(ny, nx));


		}
	}
	/*for (int y = 0; y < r; ++y)
	{
	for (int x = 0; x < c; ++x)
	{
	cout << water[y][x];
	}
	cout << '\n';
	}
	cout << '\n';*/
	return;
}

void bfs(int r, int c, pair<int, int> start, pair<int, int> end)
{
	int end_y = end.first;
	int end_x = end.second;
	/*cout << '\n' << "End axis.." << end_y << " " << end_x << '\n';*/
	queue< pair<int, int>> q;
	q.push(start);
	visited[start.first][start.second] = 0;

	flood(r, c);

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;

		if (visited[end_y][end_x] != -1)
		{
			/*for (int i = 0; i < r; ++i)
			{
			for (int j = 0; j < c; ++j)
			cout << visited[i][j] << " ";
			cout << '\n';
			}*/
			cout << visited[y][x] << '\n';

			return;
		}

		q.pop();




		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= r || nx >= c)
				continue;
			if (adj[ny][nx] == 'X' || adj[ny][nx] == '*')
				continue;
			if (visited[ny][nx] == -1)
			{
				visited[ny][nx] = visited[y][x] + 1;
				if (visited[ny][nx] < water[ny][nx] || (ny == end_y && nx == end_x))
					q.push(make_pair(ny, nx));
			}

		}
	}

	/*for (int y = 0; y < r; ++y)
	{
	for (int x = 0; x < c; ++x)
	{
	cout << visited[y][x];
	}
	cout << '\n';
	}*/

	cout << "KAKTUS\n";
	return;
}

int main()
{
	int r, c;
	cin >> r >> c;
	pair<int, int> start, end;
	adj = vector <vector <char>>(r, vector<char>(c, 0));
	visited = vector< vector<int>>(r, vector<int>(c, -1));
	water = vector< vector<int>>(r, vector<int>(c, -1));

	for (int y = 0; y < r; ++y)
		for (int x = 0; x < c; ++x)
		{
			cin >> adj[y][x];		// 물 * 돌 X 
			if (adj[y][x] == 'S')
				start = make_pair(y, x);
			else if (adj[y][x] == 'D')
				end = make_pair(y, x);
		}

	bfs(r, c, start, end);

	return 0;
}
