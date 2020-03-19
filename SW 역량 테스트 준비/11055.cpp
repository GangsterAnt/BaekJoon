//https://www.acmicpc.net/problem/11055

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 1000

vector <int> a, dp;

void dynamic()
{
	int size = a.size();
	int result = a[0];	// target is start with 1 so.. we have to initalize result as index 0 first
	for (int target = 1; target < size; ++target)
	{
		for (int compare = 0; compare < target; ++compare)
		{
			if (a[target] > a[compare] && dp[target] < dp[compare] + a[target])
			{
				dp[target] = dp[compare] + a[target];

			}

		}
		result = max(result, dp[target]);
	}

	cout << result << '\n';
}
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n,tmp;
	cin >> n;

	a = vector<int>(n, 0);
	
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		dp.push_back(a[i]);// initalize dp as a[i] ( length ==1)
	}

	dynamic();

	return 0;
}
