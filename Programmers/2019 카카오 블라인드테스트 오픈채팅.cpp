//https://www.welcomekakao.com/learn/courses/30/lessons/42888?language=cpp

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;

//string s 는 Enter uid Nickname 이 ' '을 통해 구분되어있으므로 이를 통해 파싱해야한다.
// int& i 는 명령어 "Enter ","Leave " (공백까지 6글자) "Change " ( " 7 글자) 를 넘어가기 위해서.
// i 를 주소로 받음으로써 uid 를 파싱한후 Nickname 앞 index까지 i를 옮겨놓는다.
string token_string(const string& s, int& i)
{
	string tmp = "";
	for (; i < s.size(); ++i)
	{
		if (s[i] == ' ')
		{
			i++; return tmp;
		}
		tmp += s[i];
	}

	return tmp;
}

vector<string> solution(vector<string> record)
{
	unordered_map<string, string>m;
	vector<pair<char, string>>v;
	vector<string> ans;

	for (int i = 0; i < record.size(); ++i)
	{
		string uid = ""; string nickname = "";

		if (record[i][0] == 'E')
		{
			int index = 6;
			uid = token_string(record[i], index);
			nickname = token_string(record[i], index);
			v.emplace_back(make_pair('E', uid));
			m[uid] = nickname;
		}
		else if (record[i][0] == 'L')
		{
			int index = 6;
			uid = token_string(record[i], index);
			v.emplace_back(make_pair('L', uid));
		}
		else
		{
			int index = 7;
			uid = token_string(record[i], index);
			nickname = token_string(record[i], index);
			m[uid] = nickname;
		}
	}


	for (int i = 0; i < v.size(); ++i)
	{
		string tmp = "";
		if (v[i].first == 'E')
			tmp = m[v[i].second] + "님이 들어왔습니다.";
		else
			tmp = m[v[i].second] + "님이 나갔습니다.";
		ans.push_back(tmp);
	}
	return ans;
}
