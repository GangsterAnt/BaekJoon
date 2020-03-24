//https://www.acmicpc.net/problem/6064

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int gcd(int a, int b)   // 최소 공배수 구하려고 만든 함수.. 차라리 최소 공배수 함수를 만들걸 그랬나
{
	if (a < b)
		return gcd(b, a);

	else if (a == b)
		return a;
	else if (b == 0)
		return a;
	else
		return gcd(b, a%b);
}

int main()
{
	int T, M, N, x, y;
	
	cin >> T;

	while (T--)
	{
		int ans = -1;

		cin >> M >> N >> x >> y;

		int LCM = M*N / gcd(M, N);
		int tmpx = x - 1; //  1 <= x <=M 이므로 0 <= x-1 <= M-1 로 수정해주어  ?? % M = x-1 처럼 사용
		int tmpy = y - 1;

		vector<int> v;

		int i = 0;

		while (1)   
		{
			int temp = i*M + (x - 1); // 가능성 있는수들의 모임  M으로 나눠서 나머지 x-1 이 나오는 모든 수의 집합
			if (temp <= LCM)          //단 최소 공배수 LCM 은 카잉 달력의 마지막 해이므로 upperbound 처리해준다.
			{
				v.push_back(temp);        //가능성있는 수를 모두 vector에 insert.
				i++;
			}
			else
				break;      //upperbound 넘어가면 break
		}

		for (int i = 0; i < v.size(); ++i)
		{
			if (v[i] % N == y - 1)    // V[i] 를 N 으로 나눠 y-1 이 나온다면? 찾는수이다.
				ans = v[i]+1;         // x-1 , y -1 을 통해 연산했으므로.. +1 해준다.
		}



		cout << ans << '\n';
	}

	return 0;
}
