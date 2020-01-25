//https://www.acmicpc.net/problem/14717
#include<iostream>
#include<algorithm>
#include <math.h>

using namespace std;
double winrate(int a, int b, int* cardnum);

int main()
{
	int alpha, beta;
	int cardnum[11];

	for (int i = 1; i < 11; ++i)
		cardnum[i] = 2;

	cin >> alpha >> beta;

	cout.setf(ios::fixed);
	cout.precision(3);

	cout << winrate(alpha,beta, cardnum)<<'\n';

	return 0;
}


double winrate(int a, int b, int* cardnum)
{
	double mywinrate = 0;

	if (a == b)		//10 가지 땡
	{
		double alpha = a;
		mywinrate = 1 - ((10 - alpha) / (17 * 9));		// 17*9 ==18C2 ( 상대의 총 가짓수)
		return mywinrate;
	}

	else
	{
		int sum = (a + b) % 10;

		cardnum[a] -= 1;
		cardnum[b] -= 1;
		

		for (int i = 1; i < 11; ++i)
		{
			for (int j = i; j < 11; ++j)
			{
				if (i != j)	//땡이 아니고
				{
					if (((i + j) % 10) < sum)	//낮은 끗이면서 카드가 남아있다면
					{
						if ( cardnum[i] == 2 && cardnum[j] == 2) //4 pair
						{
							//cout << i << " " << j << " Four case \n";
							mywinrate += 4;  //나보다 낮은친구... 1개 case 추가
						}
						else if ((cardnum[i] == 1 && cardnum[j] == 2)|| (cardnum[i] == 2 && cardnum[j] == 1)) //2 pair
						{
							//cout << i << " " << j << " Two case \n";
							mywinrate += 2;  
						}
					
						else if (cardnum[i] == 1 && cardnum[j] == 1) //2 pair
						{
							//cout << i << " " << j << " One case \n";
							mywinrate += 1;
						}
						
					}
				}
			}
		}
		
		mywinrate = mywinrate / 153;

		return mywinrate;

	}

}
/*


*/
