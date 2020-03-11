//https://www.acmicpc.net/problem/2206

#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,-1,1 };

 vector< vector<int>> adj;
vector< vector < vector<int>>> visited;

void bfs(int n, int m)
{
	queue < tuple<bool, int, int >> q;
	q.push(make_tuple(0, 0, 0));
	
	visited[0][0][0] = 1;

	while (!q.empty())
	{
		bool broken = get<0>(q.front());
		int y = get<1>(q.front());
		int x = get<2>(q.front());
		q.pop();

		if (y + 1 == n && x + 1 == m)
		{
			int L = visited[1][y][x];
			int R = visited[0][y][x];
			int result;

			/*for (int y = 0; y < n; ++y)
			{
				for (int x = 0; x < m; ++x)
					cout << visited[0][y][x] << " ";
				cout << "\n";
			}

			cout << '\n';
			for (int y = 0; y < n; ++y)
			{
				for (int x = 0; x < m; ++x)
					cout << visited[1][y][x] << " ";
				cout << '\n';
			}*/

			if (L != 0 && R != 0)
				result = min(L, R);
			else if (L == 0 && R != 0)
				result = R;
			else if (L != 0 && R == 0)
				result = L;

			if (result)
				cout << result << '\n';
			
			return;
		}

		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;

			if (!adj[ny][nx]  && !visited[broken][ny][nx])	//adj 가 0이고 방문 x
			{
				visited[broken][ny][nx] = visited[broken][y][x] + 1;
				q.push(make_tuple(broken, ny, nx));
			}
			if (!broken && adj[ny][nx] && !visited[1][ny][nx] )	// 벽 부순다 이제, adj 가 벽일때
			{
				visited[1][ny][nx] = visited[0][y][x] + 1;
				q.push(make_tuple(1, ny, nx));
			}
			
		}

	}
	cout << "-1\n";
	return;
}
int main()
{
	int n, m;
	cin >> n >> m;
	adj = vector< vector<int>>(n, vector<int>(m, 0)); // n x m 의 벡터
	visited = vector<vector< vector<int>>> (2, vector<vector<int>>(n, vector<int>(m, 0)));

	for (int y = 0; y < n; ++y)
		for (int x = 0; x < m; ++x)
			scanf_s("%1d", &adj[y][x]);

	bfs(n, m);

	return 0;
}
