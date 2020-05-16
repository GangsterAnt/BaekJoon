//https://www.acmicpc.net/problem/15685
//https://code.plus/lecture/351

#include<iostream>
#include <vector>

using namespace std;

int dy[] = { 0,-1,0,1 };
int dx[] = { 1,0,-1,0 };

void function(vector<vector<bool>>&v)
{
	int y, x, dir, gen;

	cin >> x >> y >> dir >> gen;


	vector<int> vd; vd.push_back(dir);

	v[y][x] = 1;

	for (int i = 0; i <= gen - 1; ++i)
	{
		//	cout << "Gen " << i << " : ";
		for (int j = vd.size() - 1; j >= 0; --j)	// 새로운 드래곤커브의 업데이트는 direction 의 역순
		{
			int ndir = (vd[j] + 1) % 4;	//마지막것의 다음방향
			vd.push_back(ndir);
		}
		/*	for (int i = 0; i < vd.size(); ++i)
		cout << vd[i] << ' ';
		cout << '\n';*/
	}

	for (int i = 0; i < vd.size(); ++i)
	{
		int ny = y + dy[vd[i]];
		int nx = x + dx[vd[i]];

		if (ny >= 0 && nx >= 0 && ny <= 100 && nx <= 100)
			v[ny][nx] = 1;
		y = ny; x = nx;
	}

}

int count(vector<vector<bool>>&v)
{
	int ans = 0;

	for (int i = 0; i < 100; ++i)
		for (int j = 0; j < 100; ++j)
			if (v[i][j] && v[i][j + 1] && v[i + 1][j] && v[i + 1][j + 1])
				ans++;

	return ans;

}
int main()
{
	vector<vector<bool>> v(101, vector<bool>(101, false));

	int n;
	cin >> n;

	for (int i = 0; i<n; ++i)
		function(v);

	/*for (int i = 0; i <= 100; ++i)
	{
	for (int j = 0; j <= 100; ++j)
	cout << v[i][j] << ' ';
	cout << '\n';
	}*/
	cout << count(v) << '\n';

	return 0;
}
