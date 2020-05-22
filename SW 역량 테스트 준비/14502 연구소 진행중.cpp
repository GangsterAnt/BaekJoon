//https://www.acmicpc.net/problem/14502
//bfs : http://codeplus.codes/f137567f00244c528fd5025e0d5c0113
//dfs : http://codeplus.codes/3cac54026c644c35b9d1598a6ae3d76c

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };


int gasout(vector<vector<int>>&v, vector< pair<int, int>> & virus)
{
	//cout << "GasOut\n";
	int ret =0;
	int n = v.size(); int m = v[0].size();

	queue< pair<int, int>> q;

	for (int i = 0; i < virus.size(); ++i)
	{
		q.push( make_pair( virus[i].first, virus[i].second)) ;
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

			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;
			if (v[ny][nx] != 0)
				continue;

			v[ny][nx] = 2;
			q.push(make_pair(ny, nx));
		}
	}

	for (int i = 0; i <n; ++i)
		for (int j = 0; j < m; ++j)
		{
			if (v[i][j] == 0)
				ret++;
		}
	return ret;
}


int dfs2( int now, vector<vector<int>>& v, vector<pair<int, int>>&virus)
{
	
	if (now == 3)
	{
		int ret = gasout(v, virus);
		//cout << "DFS DONE : "<<ret<<"\n";
		return ret;
	}

	int ans = -1;
	int n = v.size(); int m = v[0].size();

	for(int i=0; i<n; ++i)
		for (int j = 0; j < m; ++j)
		{
			if (v[i][j] == 0)
			{
				v[i][j] = 1;
				ans = max ( ans ,dfs2(now + 1, v, virus));
				v[i][j] = false;
			}
		}

	return ans;
}

//
//int dfs(int index, int now, vector<vector<int>>& v, vector<pair<int, int>>&virus)
//{
//	int ans = -1;
//
//
//	if (now == 3)
//	{
//
//		int ret = gasout(v, virus);
//		//cout << "DFS DONE : "<<ret<<"\n";
//		return ret;
//	}
//
//	int n = v.size(); int m = v[0].size();
//
//	int next = index + 1;
//	int ny = next / m;
//	int nx = next % m;
//
//	if (next < n*m - 1) // index 의 유효값
//	{
//		////다음칸에 벽 x. 어차피 벽 안지을 거니까 조건 상관 X
//		ans = max(ans, dfs(next, now, v, virus));
//
//		//다음칸에 벽 o. 조건을 따져보고 호출하자.
//
//		if (v[ny][nx] == 0)
//		{
//			v[ny][nx] = 1;			//벽세우기
//			ans = max(ans, dfs(next, now + 1, v, virus));
//			//depth 가 늘어난다.
//			v[ny][nx] = 0;
//		}
//	}
//	return ans;
//}


int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> v(n, vector<int>(m, 0));
	vector<pair<int, int>> virus;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> v[i][j];

			if (v[i][j] == 2)
				virus.push_back(make_pair(i, j));
			
		}
	}

	//cout << "DFS STart\n";
	

	cout << dfs2( 0, v, virus) << '\n';
	return 0;
}
