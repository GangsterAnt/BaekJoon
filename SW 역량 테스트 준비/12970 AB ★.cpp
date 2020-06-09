//https://www.acmicpc.net/problem/12970
//https://www.acmicpc.net/source/share/d3771f46aaa94e88abb476ed13463e45

#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, k;

	cin >> n >> k;

	// int a 는 string 에서 a의 개수를 의미한다.
	for (int a = 0; a <= n; ++a)
	{
		int b = n - a; // int b 는 string 에서 b 의 개수를 의미하고.. a+b 는 항상 n이어야한다.
		
		if (a*b < k)
			continue;	// a*b는 AAA....BBB 꼴의 string 이며 이때가 생성할수 있는 AB 쌍의 최대이다.
						// 고로 a*b <k 라면 이 a b 조합은 k개의 쌍을 생성할수 없다... continue

		vector<int> v(b + 1,0);
		//vector v 는 b개의 B를 깔아놓고.. A 가들어갈수 있는 index number이다. 0은 string 의 처음 b는 string 의 마지막.

		for (int i = 0; i <= b; ++i)	//각 index 에 대해 연산.
		{
			int pair = b - i; //해당 index 에 A 삽입시 생성되는 쌍의 개수.
			if (pair > 0)
			{
				int q = k / pair; // 해당 index에 A를 몇개 삽입할것인지 결정.

				v[i] = q;
				k = k - pair*q;
			}
		}


		for (int i = 0; i < b; ++i)
		{
			for (int j = 0; j < v[i]; ++j)
				cout << 'A';
			cout << 'B';
		}

		cout << '\n';
		return 0;

	}

	cout << "-1\n";
	return 0;
}
