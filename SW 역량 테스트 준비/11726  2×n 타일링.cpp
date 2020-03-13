//https://www.acmicpc.net/problem/11726
// iterative : F(n) = F(n-2) + F(n -1)
// because) F(n) = F(n-2)*2 + F(n -1) - F(n-2)
//				F(n-2)*2 =	남은 2X2 의 공간을 채우는건 2가지
//				F(n-1)  = 남은 2X1 공간을 채우는건 1가지
//				-F(n-2) = F(n-2) 로부터 만든것과 F(n-1) 로부터 만든것중 중복되는것의 개수
//						= F(n-1) 중에 F(n-2)로부터 만들어진것들은 F(n-2)*2 와 중복될수밖에 없다
//						= 고로 F(n-1) 중에 F(n-2) 로 만들어진것을 뺴줘야 한다.
//						== F(n-1) - F(n-2);
#include <iostream>
#define MAX 1001
#define MOD 10007
using namespace std;

int main()
{
	int arr[MAX];
	int target;

	cin >> target;

	arr[1] = 1;
	arr[2] = 2;

	for (int i = 3; i <= target; ++i)
		arr[i] = (arr[i - 2] + arr[i - 1]) %MOD;

	cout << arr[target]<<'\n';
	return 0;

}
