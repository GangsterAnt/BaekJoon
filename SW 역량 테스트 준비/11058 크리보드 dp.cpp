#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<long long> v(101, 0);

	v[1] = 1;
	v[2] = 2;
	v[3] = 3;
	v[4] = 4;

	for (int i = 5; i <= n;++i) 
	{
		v[i] = max(v[i - 1] + 1, v[i - 3] * 2); // 이전거 +1 ,3개 전꺼 복붙
		/*for (int j = 4; j < i - 2 && j<i; ++j)
			v[i] = max(v[i], v[j] * (i - 1 - j));*/
	}

	for (int i = 5; i <= n; ++i)  // i 미만 j 에서 복붙 복붙붙 복붙붙붙... 모두 비교
	{
		for (int j = 1; j < i - 3; ++j)
		{
			v[i] = max(v[i], v[j] * (i - j - 1)); //v[j] *( i- (j+2) +1) 
		}                                       // 복사할거 * ( 내가 원하는 index i , ( 복사할거 선택, 복사 하려면 +2칸 소모) 이거 뺴고 나머지 다  (( i- (j+2) +1)) 번 붙여넣기  
	}

	cout << v[n] << '\n';
	return 0;
}
