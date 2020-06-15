//https://www.acmicpc.net/problem/12904
//http://codeplus.codes/564c14b8cc57445a8791df73c9d1210e
/*
	string s에 A 나 B를 추가하는 행위는

	2^(T의 길이 - S 의 길이) 만큼의 분기가 생기고. 이 트리의 복잡도는
	worst case 에
	2^1000 이 걸리므로 2초안에 해결할수 없다.

	역으로 T 에서 S 로 가는경우

	T[T.size()-1] (마지막원소) 가 A 인경우 1번 연산
	B인경우 2번연산임을 확실히 알수 있으므로 분기가 없다.

	고로 worstcase O( 1000) 의 연산만에 해결 가능하다.
*/
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
bool function(string& s, string& t)
{
	if (t.compare(s) == 0)
		return true;
	if (s.size() >= t.size())
		return false;

	int size_t = t.size();
	
	bool ans = 0;

	if (t[size_t - 1] == 'A')
	{
		t = t.substr( 0, size_t - 1);
		ans = ans | function(s, t);
	}
	else
	{
		t = t.substr(0, size_t - 1);
		reverse(t.begin(), t.end());
		
		ans = ans | function(s, t);
	}

	return ans;

}
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string s, t;
	cin >> s >> t;
	bool ans = function(s, t);

	cout << ans << '\n';

	return 0;
}
