//https://www.acmicpc.net/problem/1806
//https://code.plus/lecture/345

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{

	int n, s;

	cin >> n >> s;
	vector<int> v(n);

	for (int i = 0; i < n; ++i)
		cin >> v[i];

	int ans = 0;

	int L = 0; int R = 0; int sum = v[0];
	while (L <= R && R < n)
	{
		if (sum == s)
		{
			int length = R - L + 1;
			if (ans == 0 || ans > length)
				ans = length;
			R++;
			if (R < n)
				sum += v[R];
			else
				break;
		}
		else if (sum < s)
		{
				R++;
				if (R < n)
					sum += v[R];
		}
		else if (sum > s)
		{
			int length = R - L + 1;
			if (ans == 0 || ans > length)
				ans = length;

			sum -= v[L];
			L++;
			if (L > R && L < n)
			{
				R = L;
				sum = v[L];
			}
		}
	}

	cout << ans << '\n';
	return 0;
}
