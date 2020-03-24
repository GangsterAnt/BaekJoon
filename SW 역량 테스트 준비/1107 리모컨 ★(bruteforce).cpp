//https://www.acmicpc.net/problem/1107

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int possible(bool* broken, int a)
{
	if (a==0)
		return broken[0] ? 0 : 1;

	int len = 0;
	while (a > 0)
	{
		if (broken[a % 10])
			return 0;
		len++;
		a /= 10;
	}
	return len;
}

int main()
{
	int n, m;
	bool broken[10];
	memset(broken, false, sizeof(broken));

	cin >> n >> m;
	for(int i=0;i <m; ++i)
	{
		int temp;
		cin >> temp;
		broken[temp] = true;

	}

	int ans = n - 100;	//init ..only with + / - button
	
	if (ans < 0)
		ans *= -1;

	for (int i = 0; i <= 1000000; ++i)
	{
		int target = i;
		int len = possible(broken, target);
		if (len > 0)
		{
			int plusminus = n - target;
			if (plusminus < 0)
				plusminus *= -1;

			ans = min(len + plusminus, ans);
		}
	}

	cout << ans << '\n';

	return 0;
}
