//https://www.acmicpc.net/problem/1208
//https://code.plus/lecture/346

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool decrease(int a, int b)
{
	return a > b;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int s, n;
	cin >> n >> s;
	

	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin>>a[i];

	int m = n - (n / 2);
	n = n - m;

	vector<int> first(1 << n,0);
	vector<int> second(1 << m,0);

	for (int i = 0; i < (1 << n); ++i)
		for (int j = 0; j < n; ++j)
			if (i & (1 << j))
				first[i] += a[j];

	for (int i = 0; i < (1 << m); ++i)
		for (int j = 0; j < m; ++j)
			if (i & (1 << j))
				second[i] += a[j+n];

	sort(first.begin(), first.end());
	sort(second.begin(), second.end(), decrease);

	/*for (int alpha = 0; alpha < first.size(); ++alpha)
		cout << first[alpha] << ' ';
	cout << '\n';
	for (int beta = 0; beta < second.size(); ++beta)
		cout << second[beta] << ' ';
	cout << '\n';*/

	n = (1 << n);
	m = (1 << m);

	long long i = 0; long long j = 0;
	long long ans = 0;

	while (i < n && j < m)
	{
		if (first[i] + second[j] > s)
		{
			//cout << "1. ";
			j++;
			//cout<< i << ' ' << j << '\n';
		}

		else if (first[i] + second[j] < s)
		{
			//cout << "2. ";
			i++;
			//cout<< i << ' ' << j << '\n';
		}

		else//first[i] + second[j] ==s
		{

			long long a = 1; long long b = 1;

			while ((first[i + a] == first[i]) && i+a<n)
					a++;
			
			while ((second[j + b] == second[j]) && j+b <m)
					b++;
			
			ans+= a*b;
			i += a; j += b;
		}
	}

	if (s == 0)
		ans -= 1;

	
	cout << ans << '\n';
	return 0;
}
