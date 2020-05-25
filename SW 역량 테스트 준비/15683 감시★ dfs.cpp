//https://www.acmicpc.net/problem/15683
//http://codeplus.codes/9dd989d8c14244019a07fd6815792da8

#include<iostream>
#include <vector>
#include <tuple>
#include <algorithm>

// 작동방식 dfs 의 depth가 끝까지 닿으면 simulate 함수를 실행.
// simulate 함수는 direction 정보를 cal 함수에 전달.
// cal 함수는 dir를 기반으로 map 에 감시 가능 구역들을 업데이트후 리턴;
// simulate 함수는 전달받은 map 을 기반으로 사각지대의 계산을 한다 O(n *m)
// dfs 호출 역순으로 리턴된다.
// dfs는 각 호출된 결과값들을 기반 min 연산을 통해 최소값을 추출해낸다.
using namespace std;

int dy[] = { -1,0 ,1 ,0 }; //상 우  하 좌
int dx[] = { 0,1,0,-1 };


//cal 함수는 map v 를 '주소로' 전달받는다. 이는 simulation 에게 수정된 map 을전달하기 위해서이다.
void cal( vector<vector<char>>&v,int dir, int y, int x)
{
	int n = v.size();
	int m = v[0].size();
	
	while (1)
	{
		 y += dy[dir];
		 x += dx[dir];

		if (y < 0 || x < 0 || n <= y || m <= x) // 유효좌표 확인.
			break;
		if (v[y][x] == '6')		//벽은 통과해서 볼수 없다.
			break;

		//cctv는 통과해서 감시할수있다.
		if (v[y][x] == '1' || v[y][x] == '2' || v[y][x] == '3' || v[y][x] == '4')
			continue;

		v[y][x] = '#';
	}


}

//simulation 함수는 map v 를 '값'으로 전달받는다. 이는 cal 함수로 map 을 수정할건데, 원본 맵을 훼손시키지 않기 위해서 이다.
int simulate(vector<int>& dir ,vector<vector<char>>v, vector<tuple<char, int, int>>&cam)
{
	int n = v.size(); int m = v[0].size();

	for (int cctv = 0; cctv < cam.size(); ++cctv)
	{
		char type; int y, x;
		tie(type, y, x) = cam[cctv];

		switch (type)
		{
			/*
				각 case 는 cctv의 종류 index 를 의미한다 ( case '1' 은... 방향 1개 감시하는 cctv)

				한가지 직선방향에 대한 함수 cal 을 만들어놓고, 각 index 에 따라 방향만 수정해서 여러번 호출하는 방식을 선택했다.
			
			*/
		case '1':
			cal(v, dir[cctv], y, x);
			break;

		case '2':
			cal(v, dir[cctv], y, x);
			cal(v, (dir[cctv]+2)%4, y, x);
			break;

		case'3':
			cal(v, dir[cctv], y, x);
			cal(v, (dir[cctv]+1)%4, y, x);
			break;

		case'4':
			cal(v, dir[cctv], y, x);
			cal(v, (dir[cctv] + 1) % 4, y, x);
			cal(v, (dir[cctv] + 2) % 4, y, x);
			break;

		case'5':
			cal(v, dir[cctv], y, x);
			cal(v, (dir[cctv] + 1) % 4, y, x);
			cal(v, (dir[cctv] + 2) % 4, y, x);
			cal(v, (dir[cctv] + 3) % 4, y, x);
			break;
		}
	}
	int ans = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (v[i][j] == '0')
				ans++;

	return ans;

}
int dfs(int now, vector<int>& dir, vector<vector<char>>& v, vector<tuple<char, int, int>> & cam)
{
	int n = v.size(); int m = v[0].size();
	int ans = n*m;

	if (now == cam.size())
	{
		return simulate(dir, v, cam);
	}

	//방향에 대한 next permutation
	for (int i = 0; i < 4; ++i)
	{
		dir[now] = i;
		ans = min(ans, dfs(now + 1, dir, v, cam));
	}

	return ans;
}
int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<char>> v(n, vector<char>(m, 0));
	vector< tuple<char,int,int>> cam;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			cin >> v[i][j];
			if (v[i][j] == '6' || v[i][j] == '0')
				continue;
			else
				cam.emplace_back(v[i][j], i, j);
		}
	vector<int> dir(cam.size(), 0);
	cout<<dfs(0,dir,v, cam)<<'\n';

	return 0;
}
