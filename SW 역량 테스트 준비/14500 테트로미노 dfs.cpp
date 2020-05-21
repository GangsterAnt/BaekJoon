//https://www.acmicpc.net/problem/14500
//http://codeplus.codes/3444842893544c3eaeb84102a066ac79
/*
	기존코드보다 24ms 더 느리고 약 300kb 절약
	vector의 크기를 구하는 size() 함수가 모든 dfs 에서 실행되므로 좀 느림.
	기존코드와의 차이점은 dfs 를 수행하며 전역변수 1개를 임시값으로 사용한 과거코드와 다르게
	지역변수 내에서 최대한 모든걸 해결했음.

	ㅗ ㅜ ㅏ ㅓ  모양코딩은 하드코딩이라 배껴옴
*/
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };


int  fuckyou(int y, int x , vector<vector<int>>&v, vector<vector<bool>>& visited)
{
	int fuckyou_ans = 0;
	int n = v.size();
	int m = v[0].size();
	int temp = 0;
	if (x + 2 < m  && y - 1 >= 0) //ㅗ 4       a
								  //			Aaa
	{
		temp = v[y][x] + v[y][x + 1] + v[y][x + 2] + v[y - 1][x + 1];
		fuckyou_ans = max(fuckyou_ans, temp);
	}
	//			a
	if (y - 1 >= 0 && y + 1 < n && x + 1 < m)	// ㅏ 5     Aa
	{											//			a
		temp = v[y][x] + v[y - 1][x] + v[y + 1][x] + v[y][x + 1];
		fuckyou_ans = max(fuckyou_ans, temp);
	}

	if (y + 1 < n && x + 2 < m) //ㅜ 6	Aaa
	{								//	 a
		temp = v[y][x] + v[y][x + 1] + v[y][x + 2] + v[y + 1][x + 1];
		fuckyou_ans = max(fuckyou_ans, temp);
	}
	//			  a
	if (y - 1 >= 0 && y + 1 <n && x - 1 >= 0)// ㅓ 7		 aA
	{										//			  a
		temp = v[y][x] + v[y - 1][x] + v[y][x - 1] + v[y + 1][x];
		fuckyou_ans = max(fuckyou_ans, temp);

	}

	return fuckyou_ans;
}

int dfs(int now, int depth, int i, int j , vector<vector<int>>&v ,vector<vector<bool>>& visited)
{
	int ret = v[i][j];
	int ans = ret;
	int n = v.size();
	int m = v[0].size();

	if( now == depth)
		return ret;

	for (int d = 0; d < 4; ++d)
	{
		int ny = i + dy[d];
		int nx = j + dx[d];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m)
			continue;
		if (visited[ny][nx])
			continue;

		visited[ny][nx] = true;
		int tmp= dfs(now + 1, depth, ny, nx, v, visited);
		ans = max(ret+ tmp, ans);
		/*
			ret += dfs 를 사용하지 않은 이유는.
			ret 이 오염되기때문이다.

			for 루프를 4번 돌며 ret 은 인접 원소 1개만 더해야 하는데 
			ret += dfs 를 사용하면 인접원소가 더해지기만 하고 뺴지지는 않기에

			지역변수 tmp 를 새로 할당하여 남은 depth 까지의 최대값을 임시 저장,

			ret 에 대입했고, ans 는 결과값이 담긴다.
		*/
		visited[ny][nx] = false;
		
	}

	return ans;
}
int function(vector<vector<int>> & v, vector<vector<bool>>& visited)
{
	int n = v.size();
	int m = v[0].size();
	int ans = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			visited[i][j] = true;
			ans = max(fuckyou(i, j, v, visited), ans);
			ans = max ( ans, dfs(0, 3, i, j, v, visited));
			visited[i][j] = false;
		}

	return ans;
}
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;

	vector< vector<int>> v(n, vector<int>(m, 0));
	vector<vector<bool>> visited(n, vector<bool>(m, false));

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> v[i][j];

	//cout << dfs(0, 3, 3, 0, v, visited);
	cout << function(v,visited) << '\n';

	return 0;

}
