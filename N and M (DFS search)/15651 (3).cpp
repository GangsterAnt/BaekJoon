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
//	cin >> n >> m;	//N �� �ִ밪  M �� ������ ����
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
//		for (int i = min; i <= max; i++)		// arr �� ù ���� �������� �����ϱ� ���� lower bound min�� �������ش�.
//		{
//			if (!visited[i])
//			{
//				arr[now] = i;
//				visited[i] = true;	// ���� ���� index i+1 ������ true ���� ������...
//				search(now + 1,i+1, max, depth);
//				visited[i] = false;		//��Ͱ� �����ڿ��� �ٽ� false �� ���� �Ǿ�� �ϹǷ�....
//			}
//
//		}
//	}
//
//}
