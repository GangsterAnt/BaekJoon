//https://www.acmicpc.net/problem/9465

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,-1,1 };

int dp[3][100001];	//0 은  y=0 선택, 1은 y=1 선택 2는 해당칸 선택 안함
int arr[2][100001];

int dynamic(int n)
{
	dp[0][1] = arr[0][1];
	dp[1][1] = arr[1][1];
	dp[2][1] = 0;

	for (int i = 2; i <= n; ++i)
	{
		dp[0][i] = arr[0][i] + max(  dp[1][i-1], dp[2][i-1]); // y=0 고른것, 안고른것
		dp[1][i] = arr[1][i] + max(dp[0][i-1], dp[2][i-1]);
		dp[2][i] = max(dp[0][i-1], dp[1][i-1]);
	}

	int temp = max(dp[0][n], dp[1][n]);
	return temp;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int c,n;
	cin >> c;

	while (c--)
	{
		memset(dp, 0, sizeof(dp));
		cin >> n;

		for (int y = 0; y <= 1; ++y)
		{
			for (int x = 1; x <= n; ++x)
				cin >> arr[y][x];
		}

		
		cout<<dynamic(n)<<'\n';
	}
	return 0;
}
