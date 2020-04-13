//https://www.acmicpc.net/problem/7453
//https://code.plus/lecture/346

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
bool decrease(int a, int b)
{
	return a > b;
}
int main()
{
	int n;

	cin >> n;

	vector<int> A(n);
	vector<int> B(n);
	vector<int> C(n);
	vector<int> D(n);

	for (int i = 0; i < n; ++i)
		cin >> A[i]>>B[i]>>C[i]>>D[i];

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	sort(C.begin(), C.end());
	sort(D.begin(), D.end());

	vector<int> AB;
	vector<int> CD;
	map<int, bool> mymap;

	for (int i = 0; i < n; ++i)
	{
		int temp = A[i];
		for (int j = 0; j < n; ++j)
			AB.push_back(temp + B[j]);
		
	}
	sort( AB.begin(), AB.end());

	for (int i = 0; i < n; ++i)
	{
		int temp = C[i];
		for (int j = 0; j < n; ++j)
			CD.push_back(temp + D[j]);
	}
	sort(CD.begin(), CD.end(), decrease);

	int i = 0; int j = 0; long long ans = 0;

	while (i < AB.size() && j < CD.size())
	{
		if (AB[i] + CD[j] == 0)
		{
			long long a = 1; long long b = 1;
	
			while ((AB[i + a] == AB[i]) &&( i + a < AB.size()))
				a++;
			while ((CD[j + b] == CD[j]) && (j + b < CD.size()))
				b++;
	
			ans += a*b;
			//cout <<ans<<' '<< a << ' ' << b << ' ' << i << ' ' << j << '\n';
			i += a;
			j += b;
	
		}
		else if (AB[i] + CD[j] > 0)
			j++;
		else
			i++;
	}

	cout << ans << '\n';
	return 0;
}
