//https://www.acmicpc.net/problem/1107

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
/*Possible 함수는 int a 에 대하여 a 의 각자리 숫자가 모두 고장나지 않았다면 a 의 길이를 리턴하고, 그렇지 않다면 0을 리턴한다
만약 임의의 target a 에 대하여 숫자버튼 입력만으로 접근이 가능하다면 숫자 a 의 길이가 a 에 접근하기 위해 입력해야하는 버튼의 개수와 같기 때문에 
e.g) 50이 접근 가능 - > 5, 0 버튼 2개만으로 50에 접근 가능 -> return 2
*/
int possible(bool* broken, int a)	
{
	if (a==0)
		return broken[0] ? 0 : 1;

	int len = 0;
	while (a > 0)
	{
		if (broken[a % 10])
			return 0;
		len++;
		a /= 10;
	}
	return len;
}

int main()
{
	int n, m;
	bool broken[10];
	memset(broken, false, sizeof(broken));

	cin >> n >> m;
	for(int i=0;i <m; ++i)
	{
		int temp;
		cin >> temp;
		broken[temp] = true;

	}

	int ans = n - 100;	//init ..only with + / - button
	
	if (ans < 0)
		ans *= -1;
/*brute force 식 접근 방식을 갖기떄문에 0 에서부터 가능한 100만 까지 모두 스캔한다.
우리가 원하는 정답 ANS 를 얻기위해서는 2가지 접근 방식을 이용한다. 숫자버튼을 이용하고, +/- 버튼을 이용하는 분기로 과정을 분리한다.*/

	for (int i = 0; i <= 1000000; ++i)
	{
		int target = i;
		int len = possible(broken, target);	// 1. len은 해당 target 까지 접근하는데 필요한 "숫자"버튼의 개수
		if (len > 0)				
		{
			int plusminus = n - target;	//2 . plusminus 는 target 에서 n(목표) 까지 "+ / - 버튼"만을 이용 접근할떄 필요한
			if (plusminus < 0)		//버튼의 개수이다.
				plusminus *= -1;

			ans = min(len + plusminus, ans);
		}
	}

	cout << ans << '\n';

	return 0;
}

/*
문제가 상당히 직관적으로 이해하기 어렵다.
우선 brutefoce 문제이므로 모든 target 에 우선적으로 숫자버튼을 통해 접근하고, 그후 +/- 버튼을 이용해 n 으로 이동한다.
그리고 그 때 까지 누른 모든 버튼의 개수가 이전에 구해놓은 ans 보다 작으면 ans 를 업데이트 한다.
이를 통해 모든 임의의수 target 에서 n 까지의 버튼거리를 구한다.




*/
