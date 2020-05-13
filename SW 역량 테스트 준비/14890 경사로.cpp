//https://www.acmicpc.net/problem/14890
//https://code.plus/lecture/351

#include <iostream>
#include <vector>

using namespace std;

int checkline(vector<int>& line, int length)
{
	int result = 0;
	int size = line.size();
	vector<bool> isset(size, false);

	for (int i = 0; i < size-1; ++i)
	{
		if (line[i] == line[i + 1])
		{
			if (i + 1 == size - 1)
				result = 1;
			continue;
		}

		else if (line[i] - line[i + 1] == -1)
		{
			if (i + 1 - length >= 0)
			{
				for (int j = i; j > i - length; --j)	//조건문을 주의하자 line[i] 는 슬로프가 실질적으로 놓여있어야 하는 블럭이다. 그러므로 for 루프는 line i를 포함해야한다.
				{
					if (line[j] != line[i])	// 슬로프를 놓을 높이가 안된다면
						return 0;			// out
					if (isset[j] == true)
						return 0;			//이미 슬로프가 놓여져있다면.
					isset[j] = true;

				}
				if (i + 1 == size - 1)
					result = 1;
			}
			else
				return 0;		// 슬로프를 놓을 길이가 안된다면
		}

		else if (line[i] - line[i + 1] == 1)
		{
			if (i + length < size)
			{
				for (int j = i + 1; j <= i + length; ++j)	// line[i] 는 슬로프가 놓이는 블럭이 아니다 그러므로 for 루프는 line[i+1] 부터 수행한다.
				{
					if (line[j] != line[i] - 1)	// 슬로프를 놓을 높이가 안된다면
						return 0;			// out
					if (isset[j] == true)
						return 0;			//이미 슬로프가 놓여져있다면.
					isset[j] = true;
				}
				if (i + 1 == size - 1)
					result = 1;
			}
			else
				return 0;		// 슬로프를 놓을 길이가 안된다면
		}
		else
			break;		//2칸 이상 높이 차이는 올라갈수 없다.
	}
	
	return result;
}

int main()
{

	//vector<int> line(6, 0);
	//line[0] = 3;
	//line[1] = 2;
	//line[2] = 1;
	//line[3] = 1;
	//line[4] = 2;
	//line[5] = 3;
	//cout<<checkline(line, 1);
	int n, l;
	int ans = 0;

	cin >> n >> l;
	
	vector<vector<int>> v(n, vector<int>(n, 0));

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> v[i][j];


	for (int i = 0; i < n; ++i)
	{
		ans += checkline(v[i], l);
		//cout << ans << "in Row " << i << " \n";
	}
	
	vector<int> temp(n);

	for (int j = 0; j < n; ++j)
	{
		for (int i = 0; i < n; ++i)
			temp[i] = v[i][j];
		ans += checkline(temp, l);
	//	cout << ans << "in Column " << j << " \n";
	}
	
	

	cout<<ans<<'\n';
	return 0;
}
