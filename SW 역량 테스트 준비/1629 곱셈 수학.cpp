//https://www.acmicpc.net/problem/1629

#include <iostream>

using namespace std;

int main()
{
	long long a, b, c;

	cin >> a >> b >> c;

	long long  ans = 1;
	//2 진수 처리.. 
		while (b > 0)
		{
			if (b & 1)
			{
				ans *= a;
			}
			a *= a;
			b = b >> 1;

			a %= c;
			ans %= c;
		}
		cout << ans << '\n';
	

	return 0;
}
