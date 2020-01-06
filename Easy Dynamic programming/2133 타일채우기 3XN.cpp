//https://www.acmicpc.net/problem/2133
//https://jaimemin.tistory.com/330

#include <iostream>
using namespace std;

int tile(int* arr,int N);
int temp = 0;

int main()
{
	int t,N;
	int arr[31] = { 0, };

	arr[0] = 0;
	arr[2] = 3;
	arr[4] = 11;
	
	cin >> N;
	cout<<tile(arr, N)<<'\n';



	return 0;
}

int tile(int* arr, int N)
{
	if (N % 2 != 0)
		return 0;
	else if (N == 0)
		return 1;
	else if (N == 2)
		return 3;

	else 
	{
		arr[N] = 3 * tile(arr, N - 2);
		for (int i = 0; i <= N - 4; i += 2)
			{
				arr[N] += 2 * tile(arr, i);
			}
		return arr[N];
	}


}
