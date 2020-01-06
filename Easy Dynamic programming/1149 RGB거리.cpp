#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/1149
//https://m.blog.naver.com/occidere/220785383050
int main()
{
	int mincost[1000][3];
	int cost[1000][3];
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
			cin >> cost[i][j];
	}

	// initialize for mincost[0]
	mincost[0][0] = cost[0][0];
	mincost[0][1] = cost[0][1];
	mincost[0][2] = cost[0][2];

	for (int i = 1; i < n; i++)
	{
		
		if (mincost[i-1][1] < mincost[i-1][2])
			mincost[i][0] = cost[i][0] + mincost[i - 1][1];
		else if (mincost[i - 1][1] >= mincost[i - 1][2])
			mincost[i][0] = cost[i][0] + mincost[i - 1][2];

		if (mincost[i - 1][0] < mincost[i - 1][2])
			mincost[i][1] = cost[i][1] + mincost[i - 1][0];
		else if (mincost[i - 1][0] >= mincost[i - 1][2])
			mincost[i][1] = cost[i][1] + mincost[i - 1][2];

		if (mincost[i - 1][0] < mincost[i - 1][1])
			mincost[i][2] = cost[i][2] + mincost[i - 1][0];
		else if (mincost[i - 1][0] >= mincost[i - 1][1])
			mincost[i][2] = cost[i][2] + mincost[i - 1][1];


	}

	int temp = mincost[n-1][0];
	for (int i = 1; i < 3; i++)
	{
		if (temp > mincost[n - 1][i])
			temp = mincost[n - 1][i];
	}

	cout << temp;

	return 0;
}
