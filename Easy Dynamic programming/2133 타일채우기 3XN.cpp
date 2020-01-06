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
	if (N % 2 != 0)		// 3 X 홀수 는  넓이 2인 타일이 자연수 갯수 있을때 채울수 없다! -> 0
		return 0;
	else if (N == 0)
		return 1;
	else if (N == 2)
		return 3;	//기저값.. 3X2 는 3가지 case 밖에 없다  

	else 
	{
		arr[N] = 3 * tile(arr, N - 2);		// 바로 직전값 에서 3X2 의 3 case 가 추가 되므로 arr[N-2]*3
		for (int i = 0; i <= N - 4; i += 2)	// N-4 부터는 각각 고유의 무늬가 생성된다 이는 이전에는 없었으므로.. 추가 계산해준다
			{
				arr[N] += 2 * tile(arr, i);
			}
		return arr[N];
	}


}
