//https://www.acmicpc.net/problem/11052

#include <iostream>
#include <algorithm>

using namespace std;

int pi[1001];
int mymax[1001];

int dp(int n)
{
	if (n == 1)
		return pi[1];

	if (mymax[n])
		return mymax[n];

	int ret=-1;

	for (int i = 1; i <= n / 2; ++i)
		ret = max( dp(i) + dp(n - i), ret);
	/*
			F(n) = max ( F(1) + F(n-1) , F(2) +F(n-2) , ...., F(n/2)+F(n/2), pi(n) ) 이므로..
				이를 for 루프로 만든것
	*/

	mymax[n] = max(ret, pi[n]);
	return mymax[n];
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> pi[i];
	cout << dp(n) << '\n';

	
	/*for (int i = 1; i <= n; ++i)
		cout<<mymax[i]<<" ";
	cout << '\n';*/
	return 0;
}
