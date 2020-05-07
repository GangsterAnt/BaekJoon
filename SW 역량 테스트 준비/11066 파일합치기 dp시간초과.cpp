//https://www.acmicpc.net/problem/11066
//https://code.plus/lecture/350

/*

행렬의 곱 연산 ( 연쇄행렬 곱셈 )
 데이터 n 개를 받는다면
 n x n 행렬 m 을 생성,
 
 m[i][j] 는 데이터 i 부터 j 까지를 합쳤을때 사용하는데이터의 최소값을 저장한다.

 이를 위해 m[i][i] = v[i] 로 세팅
 m[i][i+1] = v[i] + v[i+1] 로 세팅
 
 m[i][j] = min( m[i][i] + m[i+1][j] , m[i][i+1] + m[i+2][j] ..... m[i][j-1] + m[j][j] )가 점화식이다.

*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void dp(vector<int> &v, vector<vector<long long>>& m, vector<vector<long long>>& m2)
{
	int ans = 0;
	int n = m.size();

	ans += m[0][n - 1];
	


}

int main()
{

	int T;
	cin >> T;

	while (T--)
	{
		int n;
		cin >> n;
		int sum = 0;

		vector<int> v(n, 0);	//각 데이터 저장
		for (int i = 0; i < n; ++i)
			cin >> v[i];
		
		vector<vector<long long>> m(n, vector<long long>(n, -1)); //매트릭스


		for (int i = n - 1; i >= 0; --i)
		{
			for (int j = i; j < n; ++j)
			{
				if (j == i)
					m[i][i] = 0;
				else
					for (int k = 0; k < j - i; ++k)
					{
						int tmp = m[i][i + k] + m[i + k + 1][j];

						for (int a = i; a <= j; a++)
							tmp += v[a];
						
						if (m[i][j] == -1 || tmp < m[i][j])
							m[i][j] = tmp;
						
					}


			}
		}
		/*for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cout << m[i][j] << ' ';
			}
			cout << '\n';
		}*/
		cout << m[0][n - 1] << '\n';
	}

	return 0;
}
