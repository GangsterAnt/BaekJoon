//https://www.acmicpc.net/problem/1748

#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

long long getlen(long long  a)
{
	long long  len = 0;

	while (a >0)
	{
		a /= 10;
		len++;
	}

	return len;
}


int main()
{
	long long  n, ans, len;
	len = ans = 0;

	cin >> n;
	len = getlen(n);

	for (int i = 1; i < len; ++i)
	{
		long long temp = i * (9 * pow(10, i - 1));
		ans += temp;
	}

	long long  howmany = n - pow(10, len-1) + 1;
	howmany *= len;

	ans += howmany;

	cout << ans<<'\n';
	return 0;
}
