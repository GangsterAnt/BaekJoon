//https://programmers.co.kr/learn/courses/30/lessons/42578

#include <string>
#include <vector>
#include <map>
using namespace std;

int c_num;
vector<string> category;
map<string, int>m;

int dfs(int now, int depth)
{

}
int solution(vector<vector<string>> clothes) {
	int answer = 1;
	
	if (clothes.size() == 0)
		return 0;

	for (int i = 0; i < clothes.size(); ++i)
	{
		if (m[clothes[i][1]] == 0)
		{
			category.push_back(clothes[i][1]);
			m[clothes[i][1]]++;
		}
		else
			m[clothes[i][1]]++;
	}

	c_num = category.size();
	// 모든 경우의수 => 옷의개수 + 안입을경우 해서 i 에 대해 총 m[category[i]]+1의 경우를 갖는다.
	//하지만 모든 종류의 옷을 입지 않은경우는 제외해야하므로 ( 알몸인상태 ) 모두 안입은경우 1 을 빼준다.
	for (int i = 0; i < c_num; ++i)
	{
		answer *= (m[category[i]]+1);
	}
	answer -= 1;
	return answer;
}
