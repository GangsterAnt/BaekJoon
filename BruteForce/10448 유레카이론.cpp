//https://www.acmicpc.net/problem/10448


#include<iostream>
#include<math.h>
using namespace std;


// T(n) = n(n+1)/2  -> K ~ T( sqrt ( 2 * k)

bool possible(int target);
int summation(int first, int second, int third);

int main()
{
	int testcase;
	int test;

	cin >> testcase;
	for (int i = 0; i < testcase; ++i)
	{
		cin >> test;
		cout << possible(test) << '\n';
	}
	return 0;

}

bool possible(int target)
{

	int Max = (int)sqrt(2 * target) ;
	int temp;
	int first, second, last;
	first = second = last = 1;

	while (1)
	{
		
		temp =	summation(first, second, last);

		//cout << "First : " << first << " Second : " << second << " Thrid : " << last <<" Summation : "<<temp<<" Max : "<<Max<< '\n';

		if (temp == target)
			return 1;

		if ((first == Max) && (second == Max) && (last == Max))
			return 0;

		if (second == Max && last == Max)
		{
			first += 1;
			second = last = 1;
			continue;
		}

		if (last == Max && second != Max)
		{
			second += 1;
			last = 1;
			continue;
		}

		

		

		last += 1;
		continue;
		
		
	}

	return 0;
}


int summation(int first, int second, int third)
{
	int sum =0;
		sum += (first + 1)*first / 2;
		sum += (second + 1)*second / 2;
		sum += (third + 1)*third / 2;
	return sum;
}
