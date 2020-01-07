#include <iostream>
using namespace std;

long long bridge[31][31] = { 0, };
int m, n;
long long temp;

long long cob(int n, int m);	//case of bridge

int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> n >> m;
		temp = 0;
		cout << cob(n, m) << '\n';
	}
	return 0;
}

long long cob(int n, int m)
{
	if (n > m)
	{
		return 0;
	}
	else if (bridge[n][m] != 0)
	{
		return bridge[n][m];
	}
	else if (n == m)		//기저 1  
	{
		bridge[n][m] = 1;
		return 1;
	}
	else if (n == 1) //기저 2
	{
		bridge[n][m] = m;
		return m;
	}
	else if (n == 2)	//기저 3
	{
		
		bridge[n][m] = m*(m - 1) / 2;

		return bridge[n][m];
	}
	else
	{
		//cout << "Call!\n";
		for (int i = n - 1; i < m; i++)
		{
			bridge[n][m] +=cob(n - 1, i);
		}

		return bridge[n][m];
	}
}

/*
풀이...							이 문제를 푸는 함수를 f(n,m)이라할때;...
 N   M   (가능한 가짓수)
2	2		1				 
2	3		3 (= 1+2)
2	4		6	(=1 +2 +3)
2	M		1+ 2+ 3+ ...+ M-1 = M(M-1)/2 ...   일때를 base 로잡자 즉 f(2,m)의 기저는 M(M-1)/2 이다.

N	M
3	3		1
3	4		f(2,3) + f(2, 2) 이다.. 왜냐! N 쪽에 제일 윗 점은 M 쪽의 맨위나 그 바로 아래밖에 갈수 없다 ( 경우의수는 M-n +1 이다)
			그러면 N 쪽에 맨 위를 제외한 나머지 2개의 점이 갈수있는 경우의 수는... f(2,3) ( 맨 위끼리 매칭) + f(2, 2) ( M의 두번째와 매칭) 이다..

			이를 일반화 하면...

			f(n,m) = f(n-1 ,n-1) + f(n -1, n) + ..... + f(n-1 ,m -1) 이다.
			이를 DP 로 구현하면 된다.



*/