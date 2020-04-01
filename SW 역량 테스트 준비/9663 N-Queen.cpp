//https://www.acmicpc.net/problem/9663
//dfs

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int dy[] = { 1,1,-1,-1 };   //대각선
int dx[] = { -1,1,-1,1 };
bool column[14];
bool check(int y,int x, int depth, vector<vector<bool>>& v)
{

	//for (int i = 0; i < depth; ++i)
	//	if (v[i][x])	//같은 x에 1개라도 있으면 out
	//		return false;

	if (column[x])	//같은 x에 1개라도 있으면 out	by column 배열
		return false;

	for (int i = 0; i < 4; ++i)	//대각선 4방향
	{
		int ny = y; int nx = x;

		while (1)
		{
			ny += dy[i]; nx += dx[i];
			 
			if (ny < 0 || nx < 0 || ny >= depth || nx >= depth)
				break;	//범위 check
			if (v[ny][nx])	//킹각선에 존재시 false
				return false;
		}
	}

	return true;

}
int dfs( vector<vector<bool>>& v, int depth, int now)
{
	int ret = 0;
	if (depth == now)
		return 1;

	for (int i = 0; i < depth; ++i)
	{
		if (v[now][i])	continue;	//각 Row 에 한개씩 놓을것임 

		if (!check(now,i, depth, v)) continue;
								// 각 Row 에 1개 씩이므로 내가 관심있는 row는 검사제외
		v[now][i] = 1;
		column[i] = 1;	//어떤 column 에 놓는지 bool 배열을 사용 
						//이를 통해서... 대각선만 검증해주면 된다.
		ret+=dfs(v, depth, now + 1);

		v[now][i] = 0;
		column[i] = 0;
	}

	return ret;
}


int main()
{
	int n;
	int ans = 0;
	cin >> n;
	memset(column, false, sizeof(row));
	vector< vector<bool>> v = vector<vector<bool>>(n,  vector<bool>(n, 0));

	ans = dfs(v,n, 0);

	cout << ans << '\n';

	return 0;
}
