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
	else if (n == m)		//���� 1  
	{
		bridge[n][m] = 1;
		return 1;
	}
	else if (n == 1) //���� 2
	{
		bridge[n][m] = m;
		return m;
	}
	else if (n == 2)	//���� 3
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
Ǯ��...							�� ������ Ǫ�� �Լ��� f(n,m)�̶��Ҷ�;...
 N   M   (������ ������)
2	2		1				 
2	3		3 (= 1+2)
2	4		6	(=1 +2 +3)
2	M		1+ 2+ 3+ ...+ M-1 = M(M-1)/2 ...   �϶��� base ������ �� f(2,m)�� ������ M(M-1)/2 �̴�.

N	M
3	3		1
3	4		f(2,3) + f(2, 2) �̴�.. �ֳ�! N �ʿ� ���� �� ���� M ���� ������ �� �ٷ� �Ʒ��ۿ� ���� ���� ( ����Ǽ��� M-n +1 �̴�)
			�׷��� N �ʿ� �� ���� ������ ������ 2���� ���� �����ִ� ����� ����... f(2,3) ( �� ������ ��Ī) + f(2, 2) ( M�� �ι�°�� ��Ī) �̴�..

			�̸� �Ϲ�ȭ �ϸ�...

			f(n,m) = f(n-1 ,n-1) + f(n -1, n) + ..... + f(n-1 ,m -1) �̴�.
			�̸� DP �� �����ϸ� �ȴ�.



*/