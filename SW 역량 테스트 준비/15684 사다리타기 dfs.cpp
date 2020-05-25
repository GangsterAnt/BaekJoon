//https://www.acmicpc.net/problem/15684
//http://codeplus.codes/6d7633c7917f4a93abe98c47bf28f468

#include<vector>
#include <iostream>
#include <algorithm>

using namespace std;

int simulate(vector<vector<char>>v, vector<pair<int, int>> &addon)
{
	bool okay = true;
	int n = v[0].size();
	int h = v.size();
	
	for (int i = 0; i < addon.size(); ++i)
	{
		n, h;
		v[addon[i].first][addon[i].second] = 'L';
		v[addon[i].first][addon[i].second + 1] = 'R';
	}

	for (int i = 1; i < n; ++i)
	{
		int x = i;

		for (int j = 1; j < h; ++j)
		{
			if (v[j][x] == 'L')
				x++;
			else if (v[j][x] == 'R')
				x--;
		}

		if (x != i)
		{
			okay = false;
			return -1;
		}

	}

	return addon.size();
}

int dfs(int now, int index, vector<vector<char>>&v, vector<pair<int, int>> &addon)
{
	int h = v.size();
	int n = v[0].size();

	if (index == n*h || now == 3)
	{	//깊이가 3이거나.. index가 다돌면 시뮬레이션한다.
		return simulate(v, addon);
	}

	int ans = -1;
	int next = index + 1;
	int ny = next / n;
	int nx = next % n;

	if (next < n*h)
	{

		int tmp = dfs(now, index + 1, v, addon);	//안고르지롱
		if (ans == -1 || (ans != -1 && tmp < ans))
			ans = tmp;

		if (v[ny][nx] == false)
		{
			v[ny][nx] = true;
			addon.push_back(make_pair(ny, nx));

			int tmp2 = dfs(now + 1, index + 1, v, addon);	//고르지롱
			if (ans == -1 || (ans != -1 && tmp2 < ans))
				ans = tmp2;

			v[ny][nx] = false;
			addon.pop_back();

		}
	}

}

int main()
{
	int n, m, h;
	int y, x;

	cin >> n >> m >> h;

	vector < vector<char>> v(m + 1, vector<char>(h + 1, 'x'));

	for (int i = 0; i < m; ++i)
	{
		cin >> y >> x;
		v[y][x] = 'L';
		v[y][x + 1] = 'R';
	}

	vector<pair<int, int>> addon;
	cout << dfs(0, -1, v, addon) << '\n';

	return 0;
}
