//https://www.acmicpc.net/problem/11051
/*
	n C k 는  n개중 k 개를 고르는것의 갯수 ( 중복X )
		  이는  n-1개중 k  개를 고른것이나 n-1개중 k-1개를 고른것의 합과 같다

	n C k = n-1 C k + n-1 C k-1 
*/
#include <iostream>
#include <vector>
using namespace std;

int dp(int n, int k, vector<vector<int>>& v)
{
	if (v[n][k] != -1)
		return v[n][k];

	if (k == 0)
		return 1;
	if (n == k)
		return 1;

	v[n][k] = (dp(n - 1, k - 1,v) + dp(n - 1, k, v)) % 10007;

	return v[n][k];
}
int main()
{
	int n, k;

	vector<vector<int>>v(1001, vector<int>(1001, -1));
	v[0][0] = v[1][0] = v[1][1] = 1;
	cin >> n >> k;

	cout << dp(n, k,v)<<'\n';
	return 0;

}
