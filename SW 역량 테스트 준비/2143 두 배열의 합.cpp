//https://www.acmicpc.net/problem/2143
//https://code.plus/lecture/346

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
bool decrease(int a, int b)
{
	return a > b;
}
int main()
{
	int T, n,m;
	cin >> T >> n;
	vector<int> v1(n);
	
	for (int i = 0; i < n; ++i)
		cin >> v1[i];

	cin >> m;
	vector<int> v2(m);

	for (int i = 0; i < m; ++i)
		cin >> v2[i];


	vector<long long> sum1;
	vector<long long> sum2;

	for (int i = 0; i < v1.size(); ++i)
	{
		long long temp = 0;
		for (int j = i; j < v1.size(); ++j)
		{
			temp += v1[j];
			sum1.push_back(temp);
		}
	}

	for (int i = 0; i < v2.size(); ++i)
	{
		long long temp = 0;
		for (int j = i; j < v2.size(); ++j)
		{
			temp += v2[j];
			sum2.push_back(temp);
		}
	}

	sort(sum1.begin(), sum1.end());
	sort(sum2.begin(), sum2.end(), decrease);

	/*for (int i = 0; i < sum1.size(); ++i)
		cout << sum1[i] << ' ';
	cout << '\n';
	for (int i = 0; i < sum2.size(); ++i)
		cout << sum2[i] << ' ';
	cout << '\n';*/


	int i = 0; int j = 0; long long ans = 0;
	while (i < sum1.size() && j < sum2.size())
	{
		if (sum1[i] + sum2[j] == T)
		{
			long long a = 1; long long b = 1;

			while ((sum1[i + a] == sum1[i]) &&( i + a < sum1.size()))
				a++;
			while ((sum2[j + b] == sum2[j]) && (j + b < sum2.size()))
				b++;

			ans += a*b;
			//cout <<ans<<' '<< a << ' ' << b << ' ' << i << ' ' << j << '\n';
			i += a;
			j += b;

		}
		else if (sum1[i] + sum2[j] > T)
			j++;
		else
			i++;
	}

	cout << ans << '\n';
	return 0;
}
