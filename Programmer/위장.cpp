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

	for (int i = 0; i < c_num; ++i)
	{
		answer *= (m[category[i]]+1);
	}
	answer -= 1;
	return answer;
}
