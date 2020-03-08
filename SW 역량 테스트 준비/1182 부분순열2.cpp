// 이 문제는 brute force sln 에도 풀이가 있으나 강좌의 풀이와 다르기에 강좌 풀이대로 재 구현 해보았다.

#include <iostream>
#include <vector>

using namespace std;

int result = 0;
int arr[20];

void go(int sum,int size, int index)
{
	if (index == size)
	{
		if (sum == 0)
		{
			result++;
		}
		return ;
	}

	

	go(sum - arr[index],size, index + 1);
	go(sum,size, index + 1);

}


int main()
{
	int n, s;
	cin >> n >> s;

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	go(s,n, 0);
	if (s != 0)
		cout << result << '\n';
	else
		cout << result - 1<<'\n';
	return 0;
}
