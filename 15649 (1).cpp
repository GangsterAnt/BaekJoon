//#include <iostream>
//using namespace std;
//
//void search(int now,int max ,int detph );
//bool visited[9] = { false, };
//int arr[9];
//
//int main()
//{
//	int m, n;
//
//	cin >> n >> m;	//N 은 최대값  M 은 수열의 길이
//		
//	search(0,n,m);
//	return 0;
//
//}
//
//void search(int now, int max,int depth)
//{
//	if (depth == now)
//	{
//		for (int i = 0; i < depth; i++)
//			cout << arr[i] << " ";
//		cout << '\n';
//	}
//	else
//	{
//		for (int i = 1; i <= max; i++)		//내가 이제부터 N 이하까지 쭉 돌것이다
//		{
//			if (!visited[i])		// i 번째가 방문하지 않았다면.. !false == true
//			{
//				arr[now] = i;	//나의 리스트에 넣는다. 첨자에 주의하자! 현재 Depth 가 Now 이므로 arr[Now] 에 저장
//				visited[i] = true;	// 다음 숫자 index i+1 에서는 true 여야 하지만...
//				search(now + 1, max, depth);	// list의 원소 갯수값 (Now) 에 +1 후 재귀
//				visited[i] = false;		//재귀가 끝난뒤에는 다시 false 로 변경 되어야 하므로....
//			}
//
//		}
//	}
//
//}
