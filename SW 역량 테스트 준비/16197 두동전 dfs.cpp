//https://www.acmicpc.net/problem/16197
//http://codeplus.codes/6d2d5457ecd943b1a8c7be77a16d3973

#include <iostream>
#include <vector>

using namespace std;

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1 ,1 };

bool valid(vector<vector<char>>& v, pair<int,int>& coin)
{
	//떨어지면 false
	int n = v.size();
	int m = v[0].size();

	int y = coin.first;
	int x = coin.second;

	if (y < 0 || x < 0 || y >= n || x >= m)
		return false;

	return true;
}

int dfs(int now, int depth, vector<vector<char>>& v ,vector<pair<int,int>>& coin)
{
	int ans = -1;

	int n = v.size();
	int m = v[0].size();

	if (now == depth)
		return -1;

	auto one = coin[0];	//복귀를 위해 따로 저장
	auto two = coin[1];

	for (int i = 0; i < 4; ++i)
	{

		int ny_one = one.first + dy[i];
		int nx_one = one.second + dx[i];
		 
		coin[0]= make_pair(ny_one, nx_one);

		int ny_two = two.first + dy[i];
		int nx_two = two.second + dx[i];

		coin[1] =  make_pair(ny_two, nx_two);

		if (!valid(v, coin[0]) && !valid(v, coin[1]))	//같이 떨어진다
			continue;
		else if (valid(v, coin[0]) && !valid(v, coin[1]))	//하나만
			return now+1;
		else if (!valid(v, coin[0]) && valid(v, coin[1])) //하나만
			return now+1;

		if (v[ny_one][nx_one] == '#')
			coin[0] = one;

		if (v[ny_two][nx_two] == '#')
			coin[1] = two;

		
		int tmp =dfs(now + 1, depth, v, coin);

		if ((ans == -1 || ans > tmp ) && (tmp != -1))
			ans = tmp;

		//방문 복귀
		coin[0] = one;
		coin[1] = two;

	}

	return ans;
}
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<pair<int, int>> coin;
	vector<vector<char>> v(n, vector<char>(m));

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			cin >> v[i][j];
			if (v[i][j] == 'o')
				coin.push_back(make_pair(i, j));
		}

	cout << dfs(0,10,v, coin)<<'\n';

	return 0;
}
