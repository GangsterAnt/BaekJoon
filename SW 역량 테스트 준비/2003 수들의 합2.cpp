//https://www.acmicpc.net/problem/2003
//https://code.plus/lecture/345

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m;

	cin >> n >> m;
	vector<int> v(n,0);
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	
	int cnt = 0;

	// O(2n) 의 while 문
	int L = 0; int R = 0; int sum = v[0];
	while (L <= R && R < v.size() &&L< v.size())
	{
		if (sum == m)
		{		//정답인경우
			cnt++;
			R++;
			if( R <n)	// R 이 유효값이라면
				sum += v[R];	//R 증가와 Sum 증가
			else break;		//R == n 이라면 끝난거임
		}
		else if (sum > m)
		{
			sum -= v[L];
			L++;
			if (L > R && L < n)
			{
				R = L;
				sum = v[L];
			}
		}
		else if (sum < m)
		{
			R++;
			if (R < n)
				sum += v[R];
		}
	}

	/*
	// O(n *n )의 2중 for loop
	for (int i = 0; i < v.size(); ++i)
	{
		int sum = 0;
		for (int j = i; j < v.size(); ++j)
		{
			sum += v[j];
			if (sum == m)
			{
				cnt++;
				break;
			}
			if (sum > m)
				break;
		}
	}*/

	cout << cnt << '\n';
	return 0;
}
