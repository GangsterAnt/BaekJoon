//#include <iostream>
//using namespace std;
//
//void search(int now, int min, int max, int detph);
//int arr[9];
//
//int main()
//{
//	int m, n;
//
//	cin >> n >> m;	//N 은 최대값  M 은 수열의 길이
//
//	search(0, 1, n, m);
//	return 0;
//
//}
//
//void search(int now, int min, int max, int depth)
//{
//
//	if (depth == now)
//	{
//		for (int i = 0; i < depth; i++)
//			cout << arr[i] << " ";
//		cout << '\n';
//	}
//	else
//	{
//		for (int i = min; i <= max; i++)		// arr 의 첫 원소 이전값을 무시하기 위해 lower bound min을 설정해준다.
//		{
//			arr[now] = i;
//			search(now + 1, i, max, depth);
//		}
//	}
//
//}
