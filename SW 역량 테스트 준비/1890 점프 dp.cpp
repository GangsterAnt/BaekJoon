//https://www.acmicpc.net/problem/1890
//https://code.plus/lecture/349

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;
int dp(vector<vector<int>>& v)
{
	int n = v.size();
	vector<vector<int>> ans(n, vector<int>(n, 0));

	queue< pair<int,int>> q;
	q.push(make_pair(0, 0));
	ans[0][0] = 1;

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;

		q.pop();

		if (v[y][x]!= 0)
		{
			int ny = y + v[y][x];
			int nx = x + v[y][x];

			if (ny >= 0 && ny < n)
			{
				ans[ny][x] += ans[y][x];
				q.push(make_pair(ny, x));
			}
			if (nx >= 0 && nx < n)
			{
				ans[y][nx] += ans[y][x];
				q.push(make_pair(y, nx));
			}
		}

	}
	
	return ans[n - 1][n - 1];
}

long long dp2(vector<vector<int>>& v)
{
	int n = v.size();
	vector<vector<long long>> ans(n, vector<long long>(n, 0));
	ans[0][0] = 1;
	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < n; ++x)
		{
		
			if (ans[y][x] == 0)	//갈수 없으면 의미가 없다.
				continue;

			if (v[y][x] == 0)	// 0 칸에 도착시 의미가 없다.
				continue;		
			/*
				v[y][x] 체크를 안해주면 
				ans[y][x] += ans[ny][x]+ans[y][nx]
				( nx = x+0; ny = y+0) 이므로
				ans[y][x] *=3; 이 되어버림
			*/

			int ny = y + v[y][x];
			int nx = x + v[y][x];

			if (ny >= 0 && ny < n)
				ans[ny][x] += ans[y][x];	
			if (nx >= 0 && nx < n)
				ans[y][nx] += ans[y][x];
					

			//cout << '\n'<<y <<' '<<x<<'\n';				
			//for (int i = 0; i < n; ++i)
			//{
			//	for (int j = 0; j < n; ++j)
			//		cout << ans[i][j] << ' ';
			//	cout << '\n';				}
			//
		}
	}
	
	return ans[n - 1][n - 1];
}
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<vector<int>> v(n, vector<int>(n, 0));

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> v[i][j];
	cout << dp2(v) << '\n';
	return 0;
}
