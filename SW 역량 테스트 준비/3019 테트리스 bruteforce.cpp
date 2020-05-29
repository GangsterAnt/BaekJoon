//https://www.acmicpc.net/problem/3019
//http://codeplus.codes/fdc6555b5ba54fc692abdbe0717ad723

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> v;

int cal(int column, string s)
{
	/*
		각 열의 높이차를 구해야 한다. 
		이떄 이미 쌓인 블럭들의 높이차(v[i] -v[i+1] )와
		쌓을 블럭의 높이차 (s[i] - s[i+1]) 가 같아야 한다.. 수식으로 표현하면..
		v[i] -v[i+1] == s[i] - s[i+1] (s 는 블럭의 상대 높이 )이어야 한다
		이항해서.. 같은 index 끼리 뭉치면..

		v[i] -s[i] == v[i+1] -s[i+1] 이 된다

		index 가같아졌으므로 for 루프를 돌기 쉬워졌다.
	*/

	if (s.length() + column > v.size())
		return 0;
	int base = v[column] - s[0];

	for (int i = 1; i < s.length(); ++i)
		if (base != v[column + i] - s[i])
			return 0;

	return 1;
}
int main()
{
	int c, p, ans = 0;
	cin >> c >> p;

	v= vector<int> (c);
	for (int i = 0; i < c; ++i)
		cin >> v[i];

	for(int i=0; i<c;++i)
	{
		switch (p)
		{

		case 1:
			ans += cal(i, "0") + cal(i, "0000");
			break;

		case 2:
			ans += cal(i, "00");
			break;

		case 3:
			ans += cal(i, "001") + cal(i, "10");
			break;

		case 4:
			ans += cal(i, "100") + cal(i, "01");
			break;

		case 5:
			ans += cal(i, "000") + cal(i, "01") + cal(i, "10") + cal(i, "101");
			break;

		case 6:
			ans += cal(i, "000") + cal(i, "011") + cal(i, "20") + cal(i,"00");
			break;

		case 7:
			ans += cal(i, "000") + cal(i, "110") + cal(i, "02") + cal(i, "00");
			break;
		}
	}
	

	cout << ans << '\n';
	return 0;
}
