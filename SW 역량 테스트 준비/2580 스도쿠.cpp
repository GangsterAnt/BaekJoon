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
		{
			//cout << v[y][x] << " in " << y << ' ' << x << " is wrong with Row\n";
			return false;
		}
	}	//같은 row 에 있는 친구들은 다 true

		//check column
	for (int i = 0; i < 9; ++i)
	{
		if (y == i)	continue;
		if (target == v[i][x])
		{
			//cout << v[y][x] << " in " << y << ' ' << x << " is wrong with Column\n";
			return false;
		}
	}

	//check block
	for (int i = 3*(y / 3); i< 3*(y / 3) + 3; ++i)
		for (int j = 3* (x / 3); j < 3*(x / 3) + 3; ++j)
		{
			if (y == i &&x == j) continue;
			if (target == v[i][j])
			{
				//cout <<v[y][x]<<" in "<< i << ' ' << j << " is wrong with Block\n";
				return false;
			}
		}
	//cout << "Check for : "<<target<<" Cornet :"<< y << ' ' << x << " Is Done\n\n";

	return true;
}

void dfs(int y, int x)
{
	//cout << y << x << '\n';
	if (y == 9)
	{
		done = true;

		for (int i = 0; i < 9; ++i)
		{
			for (int j = 0; j < 9; ++j)
				cout << v[i][j] << ' ';
			cout << '\n';
		}

		return;
	}

	if (v[y][x] != 0)
	{
		if (x == 8)
			dfs(y + 1, 0);
		else
			dfs(y, x + 1);
	}

	else
		for (int i = 1; i < 10; ++i)
		{
			//cout << "i ,Y, X : " <<i<<' '<< y << ' ' << x << '\n';
			v[y][x] = i;

			if (check(y, x))
			{
				if (x == 8)
					dfs(y + 1, 0);
				else
					dfs(y, x + 1);

				if (done)
					return;
			}

			v[y][x] = 0;
		}

	return;

}

int main()
{
	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j)
			cin >> v[i][j];

	dfs(0, 0);


	

	return 0;

}
