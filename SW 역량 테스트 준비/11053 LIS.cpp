//https://www.acmicpc.net/problem/11053

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int result = 1;
int n, arr[1000],dp[1000];

void dynamic()
{
	
	for (int target = 1; target < n; ++target)
	{
		for (int compare = 0; compare < target; ++compare)
		{
			if (arr[target] > arr[compare])
			{
				dp[target] = max(dp[compare] + 1, dp[target]);
				result = max(dp[target], result);
			}
		}
	}

	
}

int main()
{
	
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	for (int i = 0; i < n; ++i)
		dp[i] = 1;

	dynamic();

	cout << result << '\n';
	return 0;
}
