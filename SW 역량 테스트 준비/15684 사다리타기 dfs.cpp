//https://www.acmicpc.net/problem/15684
//http://codeplus.codes/6d7633c7917f4a93abe98c47bf28f468

/*
	모든 원소에 대해 선택, 비선택 2 가지 분기가 나뉘므로.. 원소 300개에서..

	2^300 의 복잡도를 가진다 ㅎㅎ..
	( 물론 중간에 depth 가 3이상은 걸러지기때문에 좀더 낮지만.. 그래도 솔루션보다 몹시 느리다. 약 400ms)
	느림
*/
#include<vector>
#include <iostream>
#include <algorithm>

using namespace std;

int simulate(vector<vector<char>>&v, vector<pair<int, int>> &addon)
{
	int n = v[0].size();
	int h = v.size();
	

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
			return -1;
		
	}

	return addon.size();
}

int dfs(int now, int index, vector<vector<char>>&v, vector<pair<int, int>> &addon)
{
	int h = v.size();
	int n = v[0].size();

	if (index ==( n*h)-1 || now == 3)
	{	//깊이가 3이거나.. index가 다돌면 시뮬레이션한다.
		return simulate(v, addon);
	}

	int ans = -1;
	int next = index + 1;

	int y = index / n;
	int x = index %n;

	int ny = next / n;
	int nx = next % n;

	

		int tmp = dfs(now, index + 1, v, addon);	//안고르지롱
		
		if (tmp != -1)
		{
			if (ans != -1)
				ans = min(ans, tmp);
			else
				ans = tmp;
		}
		
		if (ny == y)	// 같은 가로칸이어야만 사다리를 놓을수 있다.
		{
			if (v[ny][nx] == 'x' && v[y][x] == 'x')	//양쪽모두 빈거여야한다 이거 중요
			{

				v[y][x] = 'L';
				v[ny][nx] = 'R';

				addon.push_back(make_pair(ny, nx));
				int tmp2 = dfs(now + 1, index + 1, v, addon);	//고르지롱

				if (tmp2 != -1)
				{
					if (ans != -1)
						ans = min(ans, tmp2);
					else
						ans = tmp2;
				}

				v[y][x] = 'x';
				v[ny][nx] = 'x';
				addon.pop_back();
			}
		}
			
		return ans;
	}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m, h;
	int y, x;

	cin >> n >> m >> h;

	vector < vector<char>> v(h + 1, vector<char>(n + 1, 'x'));

	for (int i = 0; i < m; ++i)
	{
		cin >> y >> x;
		v[y][x] = 'L';
		v[y][x + 1] = 'R';
	}

	vector<pair<int, int>> addon;
	cout << dfs(0, 0, v, addon) << '\n';
	//cout << simulate(v, addon);
	return 0;
}
