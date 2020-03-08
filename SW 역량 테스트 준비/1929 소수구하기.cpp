#include <iostream>
#include <vector>

using namespace std;
#define MAX 1000000
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	bool check[MAX] = { 0, };
	int n, m;
	vector <int> v;
	cin >> n >> m;

	for (int i = 2; i < MAX + 1; ++i)
	{
		if (check[i] == false)
		{
			v.push_back(i);
			for (int j = i * 2; j <= MAX; j +=i )
				check[j] = true;
		}
	}
	for (int i = 0; i < v.size(); ++i)
	{
		if (n <= v[i] && v[i] <= m)
			cout << v[i] << "\n";
	}
	

}
