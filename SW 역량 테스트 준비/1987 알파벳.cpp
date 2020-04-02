//https://www.acmicpc.net/problem/1987
//https://code.plus/lecture/343

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int dx[] = { 0,-1,1,0 };	//상 좌 우 하
int dy[] = { 1,0,0,-1 };
int r, c;
int ans = 1;

map<char, bool> visited;
vector<vector<char>> v;
vector<vector<int>> range;

void dfs(int y, int x)
{
	//cout << "DFS ( " << y << ' ' << x << " ) \n";


	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= r || nx >= c)
			continue;

		if (range[ny][nx] != 1)
			continue; 

		if (visited[v[ny][nx]] == true)
			continue;

		range[ny][nx] = range[y][x] + 1;
		visited[v[ny][nx]] = true;
		ans = max(ans, range[ny][nx]);

		dfs(ny, nx);

		visited[v[ny][nx]] = false;
		range[ny][nx] = 1;
	}



}
int main()
{

	cin >> r >> c;
	v = vector<vector <char>>(r, vector<char>(c, 0));
	range = vector<vector<int>>(r, vector<int>(c, 1));
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			cin >> v[i][j];

	visited[v[0][0]] = true;
	range[0][0] = 1;

	dfs(0, 0);

	cout << ans << '\n';

	return 0;
}
