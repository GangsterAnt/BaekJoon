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
//	cin >> n >> m;	//N �� �ִ밪  M �� ������ ����
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
//		for (int i = 1; i <= max; i++)		//���� �������� N ���ϱ��� �� �����̴�
//		{
//			if (!visited[i])		// i ��°�� �湮���� �ʾҴٸ�.. !false == true
//			{
//				arr[now] = i;	//���� ����Ʈ�� �ִ´�. ÷�ڿ� ��������! ���� Depth �� Now �̹Ƿ� arr[Now] �� ����
//				visited[i] = true;	// ���� ���� index i+1 ������ true ���� ������...
//				search(now + 1, max, depth);	// list�� ���� ������ (Now) �� +1 �� ���
//				visited[i] = false;		//��Ͱ� �����ڿ��� �ٽ� false �� ���� �Ǿ�� �ϹǷ�....
//			}
//
//		}
//	}
//
//}
