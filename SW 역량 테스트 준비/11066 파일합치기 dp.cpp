//https://www.acmicpc.net/problem/11066
//https://code.plus/lecture/350

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
void dp(vector<int> &v, vector<vector<long long>>& m)
{


}
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		vector<int> v(n, 0);
		for (int i = 0; i < n; ++i)
			cin >> v[i];
		vector<vector<long long>> m(n, vector<long long>(n, -1));

		
		for (int i = n - 1; i >= 0; --i)
		{
			for (int j = i; j < n; ++j)
			{
				if (j == i)
					m[i][i] = v[i];
				else
					for (int k = 0; k < j - i; ++k)
					{
						int tmp = m[i][i + k] + m[i + k + 1][j];
						if (m[i][j] == -1 || tmp < m[i][j])
							m[i][j] = tmp;
					}
			
				
			}
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j=0; j < n; ++j)
			{
				cout << m[i][j] << ' ';
			}
			cout << '\n';
		}
		//cout << m[0][n - 1] << '\n';
	}

	return 0;
}
