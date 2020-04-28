//https://www.acmicpc.net/problem/2294
//https://code.plus/lecture/349

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	vector<int> coin(n, 0);
	vector<int> cost(k + 1, -1);

	cost[0] = 0;

	for (int i = 0; i < n; ++i)
		cin >> coin[i];
	
	
	for (int i = 0; i < n; ++i)
	{
		for (int j = 1; j <= k; ++j)
		{
			if (j >= coin[i] && cost[j- coin[i]] != -1)
			{
				if (cost[j] == -1 || cost[j] > cost[j -coin[i]] +1)
					cost[j] = cost[j- coin[i]] +1;
				
			}
			//cout << j << " : " << cost[j] << '\n';
			
		}
		//cout << '\n';
	}
	if (cost[k] !=0)
		cout << cost[k] << '\n';
	else
		cout << "-1\n";
	return 0;
}
