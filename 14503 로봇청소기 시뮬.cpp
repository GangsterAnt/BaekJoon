//https://www.acmicpc.net/problem/14503
//https://code.plus/lecture/351

#include <iostream>
#include <vector>

using namespace std;

int dy[] = { -1,0,1,0 };		// 0:N 1:E 2:S 3:W
int dx[] = { 0,1,0,-1 };

void function(vector<vector<int>> &v, int y, int x, int dir)
{
	int h = v.size();
	int w = v[0].size();

	int howmany = 0;

	while (1)
	{
		//1.현재위치를 청소한다.
		v[y][x] = 2;

		int left;
		if (dir == 0)
			left = 3;
		else
			left = dir - 1;
		
		int ny = y + dy[left];
		int nx = x + dx[left];

		if (v[ny][nx] == 0)	//2.a 왼쪽방향이 청소하지 않은공간
		{
			howmany = 0;
			dir = left;		//회전하고
			y = ny; x = nx;	//전진
			continue;		//1로 돌아간다.

		}
		
		if( v[ny][nx] !=0 && howmany !=4)	//왼쪽 방향에 청소할 공간이 없다면
		{
			howmany++;
			dir = left;	//회전후
			continue;	//2로 돌아간다 continue는 1로 돌아가게 하지만 v[y][x] ==2 이므로 알아서 1을 무시하고 2로 돌아간다.
		}

		if (howmany == 4)	//네방향 모두 청소가 되어있거나 벽
		{
			int back = (dir + 2) % 4;	//뒤
			int back_x = x + dx[back];
			int back_y = y + dy[back];

			if (v[back_y][back_x] == 1)		//2.d 뒤가 벽 후진불가.
			{
				//cout << "\nEnd Cornet is.. : " << y << ' ' << x << '\n';
				return;
			}
			else
			{								//2.c 방향 유지 뒤로 한칸.
				howmany = 0;				//상하좌우 초기화.
				y = back_y;
				x = back_x;
				continue;
			}
		}
	}

}

int main()
{
	int w, h;
	cin >> h >> w;

	int dir, r, c;

	cin >> r >> c >> dir;	//r은 북쪽으로부터 떨어진 칸의 개수, c는 서쪽으로 부터 떨어진 칸의 개수이다.

	vector<vector<int>> v(h ,vector<int>(w));

	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j)
			cin >> v[i][j];

	function(v, r, c, dir);
	int ans = 0;

	/*cout << "\nReuslt : \n";
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
			cout << v[i][j] << ' ';
		cout << '\n';
	}*/

	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j)
			if (v[i][j] == 2)
				ans++;
		
	cout << ans << '\n';
	return 0;

}
