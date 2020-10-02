//https://programmers.co.kr/learn/courses/30/lessons/42628
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <iostream>

using namespace std;

bool cmp(int a, int b)
{
	return a > b;
}
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

vector<int> solution(vector<string> operations) 
{
	vector<int> answer;
	deque<int> q;

	string pop_f = "D 1";//최대값
	string pop_b = "D -1"; //최소값

	for (int i = 0; i < operations.size(); ++i)
	{
		if (q.empty())
		{
			if (operations[i] == pop_f || operations[i] == pop_b)
				continue;
		}

		if (operations[i] == pop_f)
		{
			q.pop_front();
		}
		else if (operations[i] == pop_b)
		{
			q.pop_back();
		}
		else
		{
			string num = "";
			int index = 0;

			token_string(operations[i], index);
			num = token_string(operations[i], index);
			int insert = stoi(num);
			q.push_back(insert);
		}

		sort(q.begin(), q.end(),cmp);

		/*for (int i = 0; i < q.size(); ++i)
			cout << q[i] << ' ';
		cout << '\n';*/
	}

	if (q.empty())
	{
		vector<int> tmp;
		tmp.push_back(0);
		tmp.push_back(0);

		return tmp;
	}

	else
	{
		vector<int> tmp;
		tmp.push_back( q.front());
		tmp.push_back(q.back());

		return tmp;
	}
	return answer;
}
