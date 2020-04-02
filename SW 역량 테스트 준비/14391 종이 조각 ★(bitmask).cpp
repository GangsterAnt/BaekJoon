//https://www.acmicpc.net/problem/14391
//https://code.plus/lecture/344

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main()
{
	int Max = 0;
	int n, m;
	vector<vector<int>> v;

	cin >> n >> m;
	v = vector<vector<int>>(n, vector<int>(m, 0));

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			scanf_s("%1d", &v[i][j]);

	for (int i = 0; i < (1<<(n*m)); ++i)  //모든 case 0000 0000 0000 0000 부터 1111 1111 1111 1111까지
	{
		int sum = 0;

		for (int y = 0; y < n; ++y)
		{
			int now = 0;

			for (int x = 0; x < m; ++x) // 가로로 자른것 먼저 비교.. x먼저 증가 , 해당 bit가 0일경우 가로 방향
			{
				int target = y*m + x;	//현재 보고있는 index
				if ( (i& (1 << target)) == 0)
					now = now * 10 + v[y][x];
				else
				{
					sum += now; //막혀서 끝까지 못간경우.. sum 과 now 업데이트
					now = 0;
				}
			}
			sum += now;// 막힘없이 끝까지 간경우.. 따로 구분
		}

		for (int x = 0;x < m; ++x)
		{
			int now = 0;
			for (int y= 0; y < n; ++y)  // 세로로 자른것 먼저 비교.. y먼저 증가 , 해당 bit가 1일경우 세로 방향
			{
				int target = y*m + x;
				if (i& (1 << target))
					now = now * 10 + v[y][x];
				else
				{
					sum += now;   //막혀서 끝까지 못간경우.. sum 과 now 업데이트
					now = 0;
				}
			}
			sum += now; // 막힘없이 끝까지 간경우.. 따로 구분
		}
		Max = max(Max, sum);
	}


	cout << Max << '\n';
	return 0;
}
