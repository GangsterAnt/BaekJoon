//https://www.acmicpc.net/problem/2231

#include<iostream>
#include <math.h>
using namespace std;

int composite( int target, int length);

int main()
{
	int n, temp;
	cin >> n;
	temp = n;
	int length = 0;

	while (temp >= 10 )
	{
		temp = temp / 10;
		length += 1;
	}
//	cout << temp << " " << length << '\n';
	cout << composite(n, length);		// temp 100 -> length == 2
	return 0;
}

int composite( int target, int length)
{
	int tmp = pow(10,length-1);
	int tmp2 = tmp;
	int offset =tmp;

	while (tmp2 != target)
	{
		if (tmp2 > target)
			return 0;
		for (int i = 0; i < length+1; ++i)
			{
				tmp2 += tmp % 10;
				tmp = tmp / 10;
			}

		//cout << " 점검  " << tmp2<<" "<< offset<< "\n";
		if (tmp2 == target)
			return offset;
		else
		{
			offset += 1;
			tmp = offset;
			tmp2 = tmp;
		}
	}

}
