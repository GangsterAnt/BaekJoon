//https://www.acmicpc.net/problem/5557
//https://code.plus/lecture/350

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	n--;

	vector<int> v(n);
	vector<vector<long long >> dp(n, vector<long long>(21, 0));
	// dp[i][j] 는 i까지의 v를 사용해서 합계 j 를 만드는 가지의 수를 의미한다.
	//1495 기타리스트의 solution 과 비슷하다.
	// 중간 합계는 0 -20 을 벗어날수 없다.
	// 이를 이용하자.

	//dp[i][j] = dp[i-1][j -v[i-1]] + dp[i-1][j+v[i-1] 이 될것이다.
	
	int result;

	for (int i = 0; i < n; ++i)
		cin >> v[i];
	cin >> result;

	dp[0][v[0]] = 1;	//초기값 setting

	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j <= 20; ++j)
		{
			if (dp[i - 1][j])
			{
				if(j + v[i] <=20)
					dp[i][j + v[i]] += dp[i - 1][j];
				if (j - v[i] >= 0)
					dp[i][j - v[i]] += dp[i - 1][j];
			}
		}
	}

	/*for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j <= 20; ++j)
			cout << dp[i][j] << ' ';
		cout << '\n';
	}*/

	cout << dp[n-1][result] << '\n';
	return 0;
}
