//https://www.acmicpc.net/problem/2210
//http://codeplus.codes/8817cd1563ab4ac58f9bf440c4b76401

#include <iostream>
#include <vector>
#include <map>

/*
	map 라이브러리 이용 중복 걸러내기, vector.unique 이용 중복 걸러내기.

	중에서 vector 는 sort 와 unique 하려면 O(n) 걸리기도 하고. 
	( map 은 각원소 search 가  O( lg(n)) 이므로 모든 원소에 대해 n log n  이고   추가 연산  sort 가 필요없다)

	vector는 마지막 원소를 넣었다 뻈다 하면서 dfs 를 진행하지만
	map 을 이용하면 종료 조건에서 map 에 삽입하고 그냥 종료해도 무방하다.
*/
using namespace std;

int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };

void dfs(int now, int num, int y, int x , vector<vector<int>>&v , map<int,bool>&map)
{
	num = num * 10 + v[y][x];

	if (now == 5)
	{
		if (!map[num] )
			map[num] = true;

		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5)
			continue;
		dfs(now + 1, num, ny, nx, v, map);
	}

}

int solution( vector<vector<int>>&v)
{
	map<int, bool> map;
	int ans = 0;

	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			dfs(0, 0, i, j,v,map);

	ans = map.size();

	return ans;
}

int main()
{
	vector<vector<int>> v(5, vector<int>(5, 0));

	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			cin >> v[i][j];

	cout << solution(v) << '\n';

	return 0;
}
