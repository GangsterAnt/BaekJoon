//https://www.acmicpc.net/problem/11659
/*
	sub sum 을 이용해도 N^2 의 복잡도..

	Sub[i] = A1 + A2...+A[i] 라 let

	(Sub[j] - Sub[i-1]) % M == 0 

	== Sub[j] % M - Sub[i-1] %M ==0

	>> Sub[j] % M == Sub[i-1] % M  i j 쌍을 구하는것

	마찬가지로 N^2 이므로.. Space 를 더써서..

	Sub[A] % M 의 개수를 저장해놓는 Mod vector를 생성.

	Sub[A]%M == a 라면  Mod[ a ] 와 쌍을 이룰수 있는 i < A 일때의 Mod[a] 만큼이 정답에 추가된다.

	sub 벡터가 10101 + 1 이 될때 새로 들어간 +1 은 index 1 3 5 와 쌍을 이룰수 있으므로 +3 ( == Mod 1 )

	고로 ans ++ Mod[ a ];  Mod[ a ] ++;

	이떄 주의해야 할 점이 Sub[i] % M == 0 으로 떨어지는경우인데

	이를 위해서 Mod[0] 의 초기값은 1 이 되어야 한다
	( M 으로 나뉘는 최초의 sub[i] 와 쌍을 이뤄 주기 위해서)
*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	long long  ans = 0;
	n++;
	vector<long long> v(n, 0);
	vector<int> mod(m, 0);
	mod[0] = 1;
	for (int t = 1; t < n; ++t)
		cin >> v[t];

	for (int i = 1; i < n; ++i)
	{
		v[i] = (v[i] + v[i - 1]) % m;
		ans += mod[v[i]];
		mod[v[i]]++;
	}
	

	cout << ans << '\n';
	return 0;
}
