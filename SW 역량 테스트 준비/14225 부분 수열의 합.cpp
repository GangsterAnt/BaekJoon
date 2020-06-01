//https://www.acmicpc.net/problem/14225
/*
	비트마스크 http://codeplus.codes/f34cd8ee42fa4593979c064125a8fdff
	재귀함수: http://codeplus.codes/85e65e1891c444e6ad2b23fec3b244cc

*/

#include <iostream>
#include <vector>
#include <cstring>

#define UPPERBOUND 20*100000+10

using namespace std;



void dfs(int now, int depth, int sum, vector<int>& v,bool ans[])
{

	ans[sum] = true;

	if (now == depth)
		return;

	

	dfs(now + 1, depth, sum + v[now],v,ans);
	dfs(now + 1, depth, sum, v,ans);


}
int main()
{
	
	int n;
	cin >> n;
	
	vector<int>v(n);
	bool ans[UPPERBOUND];
	memset(ans, false, sizeof(ans));

	for (int i = 0; i < n; ++i)
		cin >> v[i];

	dfs(0, n ,0, v,ans);

	for (int i = 1; i < UPPERBOUND; ++i)
	{
		if (ans[i])
			continue;

		cout << i << '\n';
		break;

	}

	return 0;
}
