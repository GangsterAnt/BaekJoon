//https://www.acmicpc.net/problem/12871
//http://codeplus.codes/9fc0cebd2ab64423959762cd94be9adb

#include <iostream>
#include <string>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string s, t;
	cin >> s >> t;

	string a1, a2;
	int size_s = s.size();
	int size_t =t.size();

	for (int i = 0; i < size_t; ++i)
		a1 += s;

	for (int j = 0; j < size_s; ++j)
		a2 += t;

	int ans = a1.compare(a2);

	if (ans == 0)
		ans = 1;
	else
		ans = 0;

	cout << ans << '\n';

	return 0;
}
