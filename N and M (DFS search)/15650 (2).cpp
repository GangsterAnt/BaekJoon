//#include <iostream>
//using namespace std;
//
//void search(int now,int min,int max ,int detph );
//bool visited[9] = { false, };
//int arr[9];
//
//int main()
//{
//	int m, n;
//
//	cin >> n >> m;	//N 은 최대값  M 은 수열의 길이
//		
//	search(0,1,n,m);
//	return 0;
//
//}
//
//void search(int now,int min, int max,int depth)
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
//			if (!visited[i])
//			{
//				arr[now] = i;
//				visited[i] = true;	// 다음 숫자 index i+1 에서는 true 여야 하지만...
//				search(now + 1,i+1, max, depth);
//				visited[i] = false;		//재귀가 끝난뒤에는 다시 false 로 변경 되어야 하므로....
//			}
//
//		}
//	}
//
//}
