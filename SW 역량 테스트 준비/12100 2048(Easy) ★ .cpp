//https://www.acmicpc.net/problem/12100
//https://code.plus/lecture/344

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void tilt(vector < vector<pair<int, bool>>>& v, int k)
{
	int n = v.size();

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			v[i][j].second = false;


	while (1)
	{
		bool moved = false;
		switch (k)
		{
		case 0:	// 상
			for (int i = 1; i < n; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					if (v[i][j].first == 0)	//현재 칸이 빈칸
						continue;
					if (v[i - 1][j].first == 0)	//진행 방향이 빈칸
					{
						v[i - 1][j].first = v[i][j].first;
						v[i - 1][j].second = v[i][j].second;
						v[i][j].first = 0; // v[i][j].second = false;
						moved = true;
					}
					else if (v[i - 1][j].first == v[i][j].first)	//합치기
					{
						if (v[i][j].second == false && v[i - 1][j].second == false)
						{
							v[i - 1][j].first *= 2;
							v[i - 1][j].second = true;
							v[i][j].first = 0;
							moved = true;
						}
					}
				}
			}
			break;

		case 1:	// 하
			for (int i = n - 2; i >= 0; --i)	//아래칸부터 합치자
			{
				for (int j = 0; j < n; ++j)
				{
					if (v[i][j].first == 0)	//현재 칸이 빈칸
						continue;
					if (v[i + 1][j].first == 0)	//진행 방향이 빈칸
					{
						v[i + 1][j].first = v[i][j].first;
						v[i + 1][j].second = v[i][j].second;
						v[i][j].first = 0; // v[i][j].second = false;
						moved = true;
					}
					else if (v[i + 1][j].first == v[i][j].first)	//합치기
					{
						if (v[i][j].second == false && v[i + 1][j].second == false)
						{
							v[i + 1][j].first *= 2;
							v[i + 1][j].second = true;
							v[i][j].first = 0;
							moved = true;
						}
					}
				}
			}
			break;
		case 2:	// 좌
			for (int i = 0; i < n; ++i)
			{
				for (int j = 1; j < n; ++j)
				{
					if (v[i][j].first == 0)
						continue;
					if (v[i][j - 1].first == 0)
					{
						v[i][j - 1].first = v[i][j].first;
						v[i][j - 1].second = v[i][j].second;
						v[i][j].first = 0;
						moved = true;
					}
					else if (v[i][j - 1].first == v[i][j].first)
					{
						if (v[i][j].second == false && v[i][j - 1].second == false)
						{
							v[i][j - 1].first *= 2;
							v[i][j - 1].second = true;
							v[i][j].first = 0;
							moved = true;
						}
					}
				}
			}
			break;
		case 3:	// 우	(0,1)
			for (int i = 0; i < n; ++i)
			{
				for (int j = n - 2; j >= 0; --j)
				{
					if (v[i][j].first == 0)
						continue;
					if (v[i][j + 1].first == 0)
					{
						v[i][j + 1].first = v[i][j].first;
						v[i][j + 1].second = v[i][j].second;
						v[i][j].first = 0;
						moved = true;
					}
					else if (v[i][j + 1].first == v[i][j].first)
					{
						if (v[i][j].second == false && v[i][j + 1].second == false)
						{
							v[i][j + 1].first *= 2;
							v[i][j + 1].second = true;
							v[i][j].first = 0;
							moved = true;
						}
					}
				}
			}
			break;
		}	//switch Done;
		if (!moved)
			break;

	}
}



int check(vector<vector<int>> &v, vector<int>&dir)
{
	int ret = 0;
	int n = v.size();
	vector<vector< pair<int, bool>>> A;
	A = vector<vector<pair<int, bool>>>(n, vector<pair<int, bool>>(n, make_pair(0, false)));

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			A[i][j].first = v[i][j];


	for (int k : dir)
		tilt(A, k);	//기울이기.

	

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			ret = max(A[i][j].first, ret);

	//cout <<"RET IS :"<< ret<<'\n';

	return ret;
}


vector<int> direction(int k)
{
	vector<int> ret;

	for (int i = 0; i < 5; ++i)
	{
		ret.push_back(k & 3);
		k >>= 2;
	}

	return ret;
}


int main()
{
	int n;
	cin >> n ;

	vector< vector<int>> v;
	v = vector<vector<int>>(n, vector<int>(n, 0));

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> v[i][j];

	int ans = -1;

	for (int i = 0; i < (1 << 10); ++i)	//2비트씩 5번 = 10비트
	{
		int cnt = 0;
		vector<int> dir = direction(i);

		cnt = check(v, dir);

		if (ans == -1 || cnt > ans)
			ans = cnt;
	}
	cout << ans << '\n';
	return 0;
}

/* Test Case

3
2 2 2
4 4 4
8 8 8

ans : 16


3
256 8 128
16 0 256
0 8 0

ans : 512



*/
