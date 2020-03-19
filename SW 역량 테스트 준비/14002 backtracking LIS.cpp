//https://www.acmicpc.net/problem/14002

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, a[1000], dp[1000], trace[1000];

void dynamic()
{
	int ret = 1;
	int ret_index = 0;

	for (int i = 0; i < n; ++i)
	{
		dp[i] = 1; trace[i] = -1;
	}
	
	
	for (int target = 1; target < n; ++target)
		for (int compare = 0; compare < target; ++compare)
			if (a[compare] < a[target])
				if (dp[target] < dp[compare] + 1)
				{
					dp[target] = dp[compare] + 1;	// dp update
					trace[target] = compare; //back tracking target 의 back의 index 는 compare
					
					if (ret < dp[target])	//  update maximun value;
					{
						ret = dp[target];
						ret_index = target;
					}
				}	
		
	cout << ret << '\n';
	vector <int> tracking;  //for back tracking

	/*for (int i = 0; i < n; ++i)
		cout << a[i] << " ";
	cout << '\n';

	for (int i = 0; i < n; ++i)
		cout << dp[i] << " ";
	cout << '\n';

	for (int i = 0; i < n; ++i)
		cout << trace[i] << " ";
	cout << '\n';*/


	while (1)
	{
		tracking.push_back(a[ret_index]);
		ret_index = trace[ret_index];

		if (ret_index == -1)
			break;
	}

	reverse(tracking.begin(), tracking.end());

	for (int i = 0; i < tracking.size() ;++i)
	{
		cout << tracking[i] << " ";
	}
	cout << '\n';

}

int main()
{
	

	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	dynamic();
	return 0;

}
