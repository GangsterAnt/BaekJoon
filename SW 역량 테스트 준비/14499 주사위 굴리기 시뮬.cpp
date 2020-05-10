//https://www.acmicpc.net/problem/14499
//https://code.plus/lecture/351

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, x, y, k;

int dy[] = {0,0,0,-1,1};	// 1:E 2:W 3:N 4:S
int dx[] = {0,1,-1,0,0};

int dicex[] = { 0,0,0,0 };	// index 는 0은 윗면 2은 바닥면 
int dicey[] = { 0,0,0,0 };
vector< vector<int>> map;
vector<int> mv;

void rotate(int dir)
{
	if (dir == 1) //E
	{
		int tmp;
		tmp = dicex[0];
		for (int i = 0; i < 3; ++i)
			dicex[i] = dicex[i + 1];
		dicex[3] = tmp;

		dicey[0] = dicex[0];	//윗면은 update 된다.
		dicey[2] = dicex[2];	//밑면은 update 된다.
	}

	if (dir == 2) //W
	{
		int tmp;
		tmp = dicex[3];
		for (int i = 3; i>0; --i)
			dicex[i] = dicex[i-1];
		dicex[0] = tmp;

		dicey[0] = dicex[0];	//윗면은 update 된다.
		dicey[2] = dicex[2];	//밑면은 update 된다.
	}

	if (dir == 3) //N
	{
		int tmp;
		tmp = dicey[3];
		for (int i = 3; i >0 ; --i)
			dicey[i]= dicey[i-1];
		dicey[0] = tmp;

		dicex[0] = dicey[0];	//윗면은 update 된다.
		dicex[2] = dicey[2];	//밑면은 update 된다.
	}

	if (dir == 4) //S
	{
		int tmp;
		tmp = dicey[0];
		for (int i = 0; i < 3; ++i)
			dicey[i] = dicey[i + 1];
		dicey[3] = tmp;
		dicex[0] = dicey[0];	//윗면은 update 된다.
		dicex[2] = dicey[2];	//밑면은 update 된다.
	}

	return;
}
void function(int dir)
{
	//cout << "\nFunction : " << dir << '\n';
	int ny = y + dy[dir];
	int nx = x + dx[dir];

	if (ny < 0 || nx < 0 || ny >= n || nx >= m)
	{
		//cout <<ny<< ' '<<nx<< " Not Valid\n";
		return;		//유효값이 넘어가면 아무것도 안한다.
	}

	y = ny;  x = nx;

	rotate(dir);

	if (map[ny][nx] == 0)	
		map[ny][nx] = dicey[2];
	
	else
	{
		dicey[2] = dicex[2] = map[ny][nx];
		map[ny][nx] = 0;
	}

	/*cout << "DiceX : ";
	for (int i = 0; i < 4; ++i)
		cout << dicex[i] << ' ';
	cout << "\nDiceY : ";
	for (int i = 0; i < 4; ++i)
		cout << dicey[i] << ' ';
	cout << '\n';
	cout << ny << ' ' << nx <<" Result : " << dicex[0] << '\n';*/
	cout << dicex[0] << '\n';

}

int main()
{
	cin >> n >> m >> y >> x >> k;

	map = vector<vector<int>>(n, vector<int>(m, 0));
	mv = vector<int>(k, 0);

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> map[i][j];

	for (int i = 0; i < k; ++i)
		cin >> mv[i];

	for (int i = 0; i < mv.size(); ++i)
		function(mv[i]);	

	return 0;
}
