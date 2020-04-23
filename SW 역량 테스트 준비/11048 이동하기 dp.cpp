//https://www.acmicpc.net/problem/11048
//https://code.plus/lecture/348

#include <iostream>
#include <vector>
#include <algorithm>

int dy[] = { -1,-1,0 };
int dx[] = { 0,-1,-1 }; //위 대각 좌
using namespace std;
int dp(vector<vector<int>> & candy, vector<vector<int>> & map)
{
	int n = candy.size();
	int m = candy[0].size();

	map[0][0] = candy[0][0]; //초기화

	for (int i = 1; i < m; ++i)	// 가로 첫줄 세팅
		map[0][i] = candy[0][i] + map[0][i - 1];

	for (int i = 1; i < n; ++i) //세로 첫줄 세팅
		map[i][0] = candy[i][0] + map[i - 1][0];
	

	for (int i = 1; i < n; ++i)
	{
		for (int j = 1; j < m; ++j)
		{
			for (int dir = 0; dir < 3; ++dir)
			{
				int ny = i + dy[dir];
				int nx = j + dx[dir];
				map[i][j] = max(map[i][j], map[ny][nx]);

			}
			map[i][j] += candy[i][j];
		}
	}

	//cout << '\n';
	//for (int i = 0; i < n; ++i)
	//{
	//	for (int j = 0; j < m; ++j)
	//		cout << map[i][j] << ' ';
	//	cout << '\n';
	//}
	return map[n-1][m-1];
}
int main()
{
	int n, m;
	cin >> n >> m;
	vector< vector<int>> candy(n, vector<int>(m, 0));
	vector< vector<int>> max(n, vector<int>(m, 0));

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> candy[i][j];

	cout << dp(candy, max) << '\n';

	return 0;
}
