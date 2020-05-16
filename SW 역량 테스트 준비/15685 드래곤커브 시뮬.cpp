//https://www.acmicpc.net/problem/15685
//https://code.plus/lecture/351
/*
	generation 이 증가함에 따라 direction 의 상관관계를 봐야한다.
	( 그려보면 빠르다 )
	 0 세대가 오른쪽이라면 1세대는 위
			 왼쪽				아래
			 위					왼
			 아래				오른쪽 으로 진행된다.

	n 세대의 드래곤 커브는 n-1 세대의 마지막 점에서 시작하므로.. 그려나가야하는 점들은
	n-1 세대에서  찍힌 점의 역순으로 찍어야 한다. 
	
	for 루프를 역순으로 돌아서 방향들을 1개의 벡터에 저장
	방향을 기반으로 다음 좌표들을 계산해 나아가자.
	
*/
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
