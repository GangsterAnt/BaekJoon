//https://www.acmicpc.net/problem/14889
// 순열 ( dfs )

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 2147483647

using namespace std;

int n;
vector<vector<int>> v;
/*
		0	1	2	3

		O	O	O	O
					X
				X	O
					X	OK
			X	O	O
				O	X	OK
				X	O	OK
				X	X
		X	O	O	O
			O	O	X	OK
				X	O	OK
				X	X
			X	O	O	OK
				O	X
				X	O
				X	X

*/
int solution(int now, vector<int> &first, vector<int> &second)
{
	if (now == n)
	{
		if (first.size() != n / 2 || second.size() != n / 2)
			return -1;
		int t1 = 0;
		int t2 = 0;

		for (int i = 0; i < n / 2; ++i)
		{
			for (int j = 0; j < n / 2; ++j)
			{
				if (i == j) continue;
				t1 += v[first[i]][first[j]];
				t2 += v[second[i]][second[j]];
			}
		}
		int diff = t1 - t2;

	/*	for (int i = 0; i < n / 2; ++i)
			cout << first[i] << " ";
		cout << "Result : "<<diff<<'\n';

		for (int i = 0; i < n / 2; ++i)
			cout << second[i] << " ";
		cout << '\n';*/
		return diff < 0 ? diff*-1 : diff;

	}

	int ans = -1;
	first.push_back(now);
	int t1 = solution(now + 1, first, second);
	if (ans == -1 || (t1 != -1 && ans > t1))
		ans = t1;		//아직 ans 가 업데이트가 안됐거나 ( ans ==-1) 새로구한값 t1이 ans 보다 작거나.
	first.pop_back();

	second.push_back(now);
	int t2 = solution(now + 1, first, second);
	if (ans == -1 || (t2 != -1 && ans > t2))
		ans = t2;	//아직 ans 가 업데이트가 안됐거나 ( ans ==-1) 새로구한값 t2이 ans 보다 작거나.
	second.pop_back();

	return ans;
}

int main()
{
	
	cin >> n; 

	v = vector<vector<int>>(n, vector<int>(n, 0));

	for (int y = 0; y < n; ++y)
		for (int x = 0; x < n; ++x)
			cin >> v[y][x];
	vector<int> second, first;
	cout << solution(0,first,second) << '\n';
	return 0;
}
