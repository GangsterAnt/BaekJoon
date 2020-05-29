//https://www.acmicpc.net/problem/15686
//http://codeplus.codes/8b34ef0a70e24464ad459b8a260dab4b
/*
	기존 dfs 는 1개씩 원소를 선택해 나아갔지만.
	이번 예제에서는 1개씩 원소를 삭제해 나아가봤음.

	가장 처음 구현에서는 선택한 치킨집들을 vector 의 erase insert 를 이용해서 직접
	넣었다 뻈다 했는데 시간초과.

	insert 와 erase를 중간 원소에서 시행하는것은 매우 비효울적이기 때문에 시간 초과가 발생했다.

		 #해당 구현이 이뤄진 dfs 함수의 주석부분
		pair<int,int> tmp_store = store[i];
		vector<pair<int, int>>::iterator iter = store.begin();
		iter += i;
		store.erase(iter);	//i 번째 삭제

		int tmp = dfs(depth, v, store);

		if (ans == -1 || ans > tmp)
		ans = tmp;

		store.insert(iter , make_pair(0,0));
		//insert 함수가 tmp_store를 바로 못받길래 임의 값 생성후 변경하는 방식이용함.
		store[i] = tmp_store;
		
		시간 복잡도를 낮추기 위해 vector<bool> pick 을 통해 따로 방문처리를 해줬음.

		이때 dfs 함수의 기본 리턴값이 -1 이기 떄문에

		if( ans ==-1 || tmp <ans )
			ans = tmp ; 를 사용하면 tmp 가 -1 인 경우를 처리해주지 못한다.


			#아래코드를 이용해서 예외 처리를 거친다 
			if (tmp != -1)
			{
			if (ans != -1)
			ans = min(ans, tmp);
			else
			ans = tmp;
			} 
			

	
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int simulate(vector<vector<char>>& v, vector<pair<int, int>>& store,vector<bool>& pick)
{
	int n = v.size();
	int ans = 0;
	
		for(int i=1; i<n;++i)
			for (int j = 1; j < n; ++j)
			{
				if (v[i][j] == '1')	//집 발견하면
				{
					int dist = -1;
					for (int s = 0; s < store.size(); ++s) //모든 가게에 대한 거리 구해
					{
						if (!pick[s])
							continue;
						int y = i - store[s].first;
						int x = j - store[s].second;

						if (y < 0)
							y *= -1;
						if (x < 0)
							x *= -1;
						if (dist == -1 || dist > x + y)
							dist = x + y;
					}

					ans += dist;
				}
				
			}
	
	//cout << "Return ans : " << ans << '\n';
	return ans;
}

int dfs(int index, int now, int depth, vector<vector<char>>& v, vector<pair<int, int>>& store, vector<bool>& pick)
{
	int ans = -1;

	if (now== depth)
	{
		return simulate(v, store,pick);
	}
	int size = store.size();

	for (int i = index; i <size ; ++i)
	{
		if (pick[i])
		{
			pick[i] = false;
			int tmp = dfs(i+1,now - 1, depth, v, store, pick);
			
			if (tmp != -1)
				{
					if (ans != -1)
						ans = min(ans, tmp);
					else
						ans = tmp;
				}
			pick[i] = true;
		}
		/*pair<int,int> tmp_store = store[i];
		vector<pair<int, int>>::iterator iter = store.begin();
		iter += i;
		store.erase(iter);	//i 번째 삭제

		int tmp = dfs(depth, v, store);

		if (ans == -1 || ans > tmp)
			ans = tmp;

		store.insert(iter , make_pair(0,0));
		//insert 함수가 tmp_store를 바로 못받길래 임의 값 생성후 변경하는 방식이용함.
		store[i] = tmp_store;
		*/
	}

	return ans;

}
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;

	vector<vector<char>> v(n + 1, vector<char>(n + 1, '0'));
	vector<pair<int, int>> store;
	vector<bool> pick;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
		{
			cin >> v[i][j];
			if (v[i][j] == '2')
			{
				store.push_back(make_pair(i, j));
				pick.push_back( true);
			}
		}

	cout << dfs(0,store.size(), m, v, store, pick) << '\n';
	
	
	return 0;
}
