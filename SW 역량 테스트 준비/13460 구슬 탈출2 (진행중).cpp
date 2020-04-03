//https://www.acmicpc.net/problem/13460
//https://code.plus/lecture/344

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<int, int> __blue;
pair<int, int> __red;

int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };

vector<int> direction(int k)	// 4비트씩 끊자.
{
	vector<int> ret;
	for (int i = 0; i<10; ++i)
	{
		int temp = (k & 3);
		ret.push_back(temp);
		k >>= 2;
	}

	return ret;
}

bool check_dir(const vector<int>& dir) //상하좌우 vaild 체크
{
	for (int i=0; i<dir.size()-1;++i)
	{
		if (dir[i] == 0 && dir[i + 1] == 1) return false;
		if (dir[i] == 1 && dir[i + 1] == 0) return false;
		if (dir[i] == 2 && dir[i + 1] == 3) return false;
		if (dir[i] == 3 && dir[i + 1] == 2) return false;
		if (dir[i] == dir[i + 1]) return false;
		//if (dir[i] == 0)	//상
		//	if (dir[i + 1] == 0 || dir[i + 1] == 1)
		//		return false;
		//
		//else if (dir[i] == 1)	//하
		//	if (dir[i + 1] == 0 || dir[i + 1] == 1)
		//		return false;

		//else if (dir[i] == 2)	//좌
		//	if (dir[i + 1] == 2 || dir[i + 1] == 3)
		//		return false;
		//else if (dir[i] == 3)	//우
		//	if (dir[i + 1] == 2 || dir[i + 1] == 3)
		//		return false;
		
	}
	return true;
}



pair<bool, bool> tilt(vector<vector<char>> &v,int k, pair<int,int>& cornet)
{
	//cornet 은 temp_red or temp_blue;
	int y = cornet.first; int x = cornet.second;

	if (v[y][x] == '.') // . 이면 읨이ㅓㅄ다
		return make_pair(false, false);

	bool move = false;
	while (true)
	{
		int ny = y + dy[k]; int nx = x + dx[k];
		

		//히히.. 못가!
		if (v[ny][nx] == '#' || v[ny][nx] == 'R' || v[ny][nx] == 'B')
			return make_pair(move, false);
		else if (v[ny][nx] == '.')
		{
			swap(v[ny][nx], v[y][x]);
			y = ny; x = nx; //함수 내부의 while 문을 위한 update
			cornet = make_pair(ny, nx);	// check 함수에서 바뀐 좌표가 필요.
		}
		else if (v[ny][nx] == 'O')
		{
			v[y][x] = '.';
			move = true;
			return make_pair(move, true);
		}
		

	}
}

int check(vector <vector<char>> v, vector<int> dir)
{
	int ans = 0;
	auto temp_red = __red;
	auto temp_blue = __blue;
	for (int k : dir)
	{
		ans++;
		bool hole1 = false; bool hole2 = false;

		while (1)
		{
			auto p1 = tilt(v, k, temp_red);
			auto p2 = tilt(v, k, temp_blue);

			if (p1.first == false && p2.first == false)	//둘다 move 가 false ( 움직이지 않았다면) break;
				break;

			if (p1.second) hole1 = true;
			if (p2.second) hole2 = true;
		}

		

		if (hole2) return -1;
		if (hole1) return ans;
	}

	return -1;
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector < vector<char>> v = vector<vector<char>>(n, vector<char>(m, 0));

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			cin >> v[i][j];

			if (v[i][j] == 'R')
				__red = make_pair(i, j);
			if (v[i][j] == 'B')
				__blue = make_pair(i, j);
		}

	int ans = -1;

	for (int i = 0; i < (1 << 20); ++i)
	{
		vector<int> dir = direction(i);
		if (!check_dir(dir)) continue;
		int cnt = check(v, dir);

		if (cnt == -1)
			continue;

		if (ans == -1|| ans > cnt)
			ans = cnt;


	}
	cout << ans << '\n';
	return 0;

}
