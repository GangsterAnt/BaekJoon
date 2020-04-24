//https://www.acmicpc.net/problem/10942
//https://code.plus/lecture/349

/*

팰린드롬의 세팅
벡터 v가있다고 하자.
벡터 v 의 부분수열 s[i][j] 가 팰린드롬이라고 하자
		s[i-1][j+1] 은 v[i-1] ==v[j+1] 이면 1  != 이면 0이다
		즉 s를 2차원 행렬이라고 할때 s[i][j]의 대각선 위의 s[i-1][j+1] 1 의 여부는
		아래 두조건을 모두 만족해야한다.

		1.  s[i][j] 가 1 이어야 한다.
		2. v[i-1] ==v[j+1] 이어야한다.


*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int is_Pal(string s)
{
	
	int size = s.size();

	int last = size-1;

	for (int i = 0; i <last; ++i, last--)
	{
		if (s[i] != s[last])
		{
			return 0;
		}
	}
	return 1;
}

void matrix(const vector<int>&v, vector<vector<int>>& m)
{
	int n = v.size();

	int dy = -1;
	int dx = 1;	//대각선 오른쪽 위.

	for (int i = 0; i < n; ++i)	// m[i][i] 세팅
		m[i][i] = 1;


	for (int i = 0; i < n - 1; ++i)	// 2자리 초기값들 세팅
	{
		if (v[i] ==v[i+1])
			m[i][i + 1] = 1;
	}

	for (int k = 3; k <= n; k++)	// k는 i~ j 까지의 길이
	{
		for (int i = 0; i <= n - k; i++) 
		{
			int j = i + k - 1;
			if (v[i] == v[j] && m[i + 1][j - 1]) 
				m[i][j] = 1;
		}
	}

	return;
}


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n;
	vector< vector<int>> mat(n, vector<int>(n, 0));
	vector<int> v(n,-1);

	for (int i = 0; i < n; ++i)
		cin >> v[i];
	
	matrix(v, mat);
	cin >> m;

	while (m--)
	{
		int s, e;
		cin >> s >> e;
		
		cout << mat[s-1][e-1]<<'\n';
	}

	return 0;
}
