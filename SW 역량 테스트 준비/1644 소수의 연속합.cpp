//https://www.acmicpc.net/problem/1644
//https://code.plus/lecture/345

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	if (n == 1)
	{ //1 
		cout << "0\n";
		return 0;
	}
	vector<bool> is_prime(n + 1,true);
	vector<int> v;
	for (int i = 2; i <= n; i++)
	{		//에라토스테네스의 체
		if (is_prime[i])
		{
			v.push_back(i);
			for (int j = i * 2; j <= n; j += i)
				is_prime[j] = false;
		}

	}
	int size = v.size();
	int L = 0; int R = 0; int ans = 0; int sum = v[0];
	if (size == 0)
	{ //벡터가 비었을떄 예외처리
		cout <<"0\n";
		return 0;
	}
	while (L <= R && R < v.size())
	{
		if (sum == n)
		{
			ans++;
			R++;
			if (R < n)
				sum += v[R];
			else
				break;
		}
		else if (sum < n)
		{
			R++;
			if (R < n)
				sum += v[R];
			else
				break;
		}
		else if (sum > n)
		{
			sum -= v[L];
			L++;
			if (L > R && L < size)
			{
				R = L;
				sum = v[L];
			}
		}
	}
	
	cout << ans << '\n';
	return 0;
}
