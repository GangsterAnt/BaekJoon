//https://www.acmicpc.net/problem/14226

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector< vector<int>> adj = vector<vector<int>>( 1001, vector<int>(1001,0));

void bfs(int fin)
{
	queue <pair<int, int>> q;
	adj[0][1] = 0;	// row index 는 clipboard 에 있는 이모티콘
	q.push(make_pair(0, 1));

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		if (x == fin)
		{
			cout << adj[y][x] << '\n';
			return;
		}

		int dy[] = { x, y, y };		//1 .화면에 있는 이모티콘을 모두 복사해서 클립보드에 저장한다.
		int dx[] = { x, x + y,x - 1 };	//2. 클립보드에 있는 모든 이모티콘을 화면에 붙여넣기 한다.
										//3. 화면에 있는 이모티콘 중 하나를 삭제한다.
		for (int i = 0; i < 3; ++i)
		{
			if (dy[i] < 0 || dx[i] < 0 || dy[i]>1000 || dx[i] >1000)
				continue;
			if (!adj[dy[i]][dx[i]])
			{
				adj[dy[i]][dx[i]] = adj[y][x] + 1;
				q.push(make_pair(dy[i], dx[i]));
			}
		}
	}

}

int main()
{
	int fin;
	cin >> fin;

	bfs(fin);

	return 0;
}
