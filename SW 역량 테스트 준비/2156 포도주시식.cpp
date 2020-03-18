//https://www.acmicpc.net/problem/2156

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int arr[10001];
int dp[3][10001];

int dynamic(int n)	//2차원 배열
{
	dp[0][1] = 0;
	dp[1][1] = arr[1];

	/*dp[0][2] = dp[1][1];
	dp[1][2] = arr[2];
	dp[2][2] = arr[1] + arr[2];*/
	

	for (int i = 2; i <= n; ++i)
	{
		int tmp = max(dp[1][i - 1], dp[2][i - 1]);
		dp[0][i]= max(dp[0][i - 1], tmp);		//dp[0][i] = max(dp[0][i-1],dp[1][i-1],dp[2][i-1]) 
		dp[1][i]= arr[i] + dp[0][i-1];			// 2번 건너뛰어야 최대인 경우도 있기때문에
		dp[2][i]= arr[i] + dp[1][i-1];			// max 안에 dp[0][i-1]도 있어야함
	}											// 없을시.. 반례 6) 2 1 0 0 8 9
	int temp = max(dp[0][n], dp[1][n]);			//			 정답 ) o o x x o o ->20
	temp = max(dp[2][n], temp);					//			 오답 ) o x o x o o ->19

	return temp;
}

int dynamic2(int n)
{
	int dp[10001];
	dp[0] = 0;
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	for (int i = 3; i <= n; ++i)
	{											//dp [i]의 case는 3개중 하나다
		dp[i] = max(dp[i - 1], dp[i - 2] + arr[i]);	//안마실때 ??X ==dp[i-1] , 첫번째로 마실때  ???XO dp[i - 2] + arr[i]
		dp[i] = max(dp[i], dp[i - 3] + arr[i - 1] + arr[i]);	//두번째로 마실때 ???XOO  dp[i - 3] + arr[i - 1] + arr[i]
	}

	return dp[n];
}

int main()
{
	memset(dp, 0, sizeof(dp));
	memset(arr, 0, sizeof(arr));
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> arr[i];

	cout<<dynamic2(n)<<'\n';

	return 0;
}
