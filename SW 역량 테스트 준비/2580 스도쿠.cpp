//https://www.acmicpc.net/problem/2580
//https://code.plus/lecture/343

#include<iostream>
#include <vector>
#include <cstring>
using namespace std;

vector < vector<int>> v = vector<vector<int>>(9, vector<int>(9, 0));
bool done = false;

bool check(int y, int x)
{
	int target = v[y][x];


	//check row
	for (int i = 0; i < 9; ++i)
	{
		if (x == i)	continue;

		if (target == v[y][i])
			return false;
	}	//같은 row 에 있는 친구들은 다 true
	
	//check column
	for (int i = 0; i < 9; ++i)
	{
		if (y == i)	continue;

		if (target == v[i][x])
			return false;
	}
	
	//check block
	for (int i = y/3; i< (y/3)+3 ; ++i)
		for (int j = x / 3; j < (x / 3) + 3; ++j)
		{
			if (y == i &&x == j) continue;
			if (target == v[i][j])
				return false;
		}
	
	return true;
}

void dfs(int y, int x)
{

	if (y == 8 && x == 8)
	{
		done = true;
		return;
	}

	for (int i = 1; i < 10; ++i)
	{
		if (v[y][x] != 0)
			continue;

		v[y][x] = i;

		if (check(y, x))
		{
			if (x != 8)
				dfs(y, x + 1);
			else
				dfs(y + 1, 0);
		}
		if (done)
			return;

		v[y][x] = 0;

	}



}

int main()
{
	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j)
			cin >> v[i][j];


	dfs(0,0);


	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
			cout << v[i][j] << ' ';
		cout << '\n';
	}

	return 0;

}
