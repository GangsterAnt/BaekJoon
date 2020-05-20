//https://www.acmicpc.net/problem/3568
//http://codeplus.codes/7cecc52a12c24dbb982897be559bb147

#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

char a[] = { '&', '*', '[' };

vector<string> tokken(string & s)
{
	vector<string> ret;
	
	string tmp;
	for (int i= 0; i< s.length(); ++i)
	{
		if (s[i] == ' ' || s[i] == ',' || s[i] == ';')
		{
			if(tmp.size() >0)		//비었는데도 추가할수 있으므로.. 없을시 공백 야기함
				ret.push_back(tmp);
			tmp = "";
			// ='\0' 이 아닌 이유는 tmp 가 string 이므로 끝에 널문자가 없다.
			// char []  과 다르다.
		}
		else
			tmp += s[i];
	}

	for (int i = 1; i < ret.size(); ++i)
	{
		string name;
		string ref;
		for (int k = 0; k < ret[i].size(); ++k)
		{
			if (ret[i][k] == '*')
				ref.insert(0, "*");

			else if (ret[i][k] == '&')
				ref.insert(0, "&");

			else if (ret[i][k] == '[')
			{
				k++;
				ref.insert(0, "[]");
			}
			else if (ret[i][k] == ' ')
				;
			else
				name += ret[i][k];
		}

		ret[i] = ret[0]+  ref +' '+ name + ';';
	}

	ret.erase( ret.begin());
	


	return ret;
}

int main()
{
	string s;
	
	getline(cin, s);
	
	vector<string> ans;

	ans = tokken(s);
	for (string S : ans)
		cout << S << '\n';
	return 0;
}
