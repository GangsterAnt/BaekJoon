//https://www.acmicpc.net/problem/1699

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 100001

int d[MAX];

int main()
{
	for (int i = 0; i < MAX; ++i)		//초기값
		d[i] = 999999999;

	for (int i = 1; i*i < MAX; ++i)
		d[i*i] = 1;			//제곱수 i*i의 초기값은 1


	for(int i=1; i<MAX ; ++i)
		for (int k = 1; i + k*k < MAX; ++k)
		{
			d[i + k*k] = min(d[i] + 1, d[i + k*k]);
		}

	int n;
	cin >> n;

	cout << d[n]<<'\n';

	/*cout << "Debuging....\n";

	for (int i = 1; i < MAX; ++i)
		cout << d[i] << " ";*/

	return 0;
}

/*
강의에서..
D[N] = min (D[N-i*i] +1 )
( while  1<= i*i <= N 
	... 시간 복잡도 O( N^(3/2)) 

	for(int i=1; i<=n ; i++)
		d[i] = i; 
		for(int j=1; j*j <=i ; j++)
			if(d[i] > d[i-j*j] +1)
				d[i] = d[i-j*j] +1;
		

*/
