#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

void dfs(int n_temp, int m_temp,int sum,int depth);
void fuckyou(int n, int m);
int solve();

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int dfs_ans = 0;
int fuckyou_ans = 0;
int n, m;
bool visited[500][500] = { false, };
int arr[500][500];


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> arr[i][j];

	cout << solve()<<'\n';

	return 0;
}


int solve()
{

	int result = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			memset(visited, false, sizeof(visited));
			dfs(i, j, 0, 0);
			fuckyou(i, j);
			//cout << "Result on " << i << " " << j<<" is... " << max(fuckyou_ans, dfs_ans)<< "\n";
		}
	}

	return max(fuckyou_ans, dfs_ans);
}


//void dfs(int y, int x, int Sum, int Cnt)
//{
//	visited[y][x] = true;
//
//	if (Cnt == 3)
//	{
//		dfs_ans = max(dfs_ans, Sum);
//		return;
//	}
//
//	for (int i = 0; i < 4; i++)
//	{
//		int nx = x + dx[i];
//		int ny = y + dy[i];
//
//		if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
//		if (visited[ny][nx] == true) continue;
//
//		dfs(ny, nx, Sum + arr[ny][nx], Cnt + 1);
//		visited[ny][nx] = false;
//	}
//}


void dfs(int n_temp, int m_temp,int sum, int depth)
{
	int result = sum + arr[n_temp][m_temp];
	visited[n_temp][m_temp] = true;

	if (depth == 3)
	{
		dfs_ans = max(dfs_ans, result);
		return;
	}


	for (int i = 0; i < 4; ++i)
	{
		
		int y = n_temp + dy[i];
		int x = m_temp + dx[i];
		
		if (0 <= y && y < n && 0 <= x && x < m)
		{
			if (!visited[y][x])
			{
				dfs(y, x, result, depth + 1);
				visited[y][x] = false;
			}
		}
	
	}

	//visited[n_temp][m_temp] = false;
}


void fuckyou(int y, int x)
{
	int temp = 0;
	if (x + 2 < m  && y -1 >=0) //ㅗ 4       a
								//			Aaa
	{
		temp = arr[y][x] + arr[y][x+1]  + arr[y][x +2] + arr[y - 1][x + 1];
		fuckyou_ans = max(fuckyou_ans, temp);
	}
												//			a
	if (y - 1 >= 0 && y + 1 < n && x + 1 < m)	// ㅏ 5     Aa
	{											//			a
		temp = arr[y][x] + arr[y - 1][x] + arr[y + 1][x] + arr[y][x+1];
		fuckyou_ans = max(fuckyou_ans, temp);
	}

	if (y + 1 < n && x + 2 < m) //ㅜ 6	Aaa
	{								//	 a
		temp = arr[y][x] + arr[y][x + 1] + arr[y][x + 2] + arr[y + 1][x + 1];
		fuckyou_ans = max(fuckyou_ans, temp);
	}
											//			  a
	if (y - 1 >= 0 && y+1 <n && x -1 >= 0)// ㅓ 7		 aA
	{										//			  a
		temp = arr[y][x] + arr[y -1][x] + arr[y][x -1] + arr[y +1][x];
		fuckyou_ans = max(fuckyou_ans, temp);

	}

}







/*

4 4
0 0 0 0
0 0 0 0
0 0 3 4
0 1 2 0		9


4 4
0 0 0 0
0 0 2 1
0 0 3 0
0 0 4 0		 9


4 4
0 0 0 0
0 0 0 0
0 1 2 3
0 4 0 0    7

*/
