#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> set1, set2;

int function(vector<string>& a, vector<string>& b)
{
	vector<string> tmp;

	for (int i = 0; i < a.size(); ++i)
		tmp.push_back(a[i]);

	for (int i = 0; i < b.size(); ++i)
		tmp.push_back(b[i]);

	sort(tmp.begin(), tmp.end());
	tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());

	for (int i = 0; i < tmp.size(); ++i)
	{
		cout << tmp[i] << ' ';
	}
	cout << '\n';

	for (int i = 0; i < a.size(); ++i)
	{
		cout << a[i] << ' ';
	}
	cout << '\n';

	for (int i = 0; i < b.size(); ++i)
	{
		cout << b[i] << ' ';
	}
	cout << '\n';


	float common =0;
	float   all = tmp.size();
	for (int i = 0; i < tmp.size(); ++i)
	{
		int A = count(a.begin(), a.end(), tmp[i]);
		int B = count(b.begin(), b.end(), tmp[i]);

		cout << tmp[i] << " in A " << A << " ... in B " << B << '\n';
		if (A >= 1 && B >= 1)
		{
			common += min(A, B);
			all += (max(A, B) - 1);
		}
	}
	cout << "C : " << common << " A : " << all << '\n';
	float ans = common / all;
	
	ans *= 65536;

	return  (int)ans;
}



int solution(string str1, string str2) {
	int answer = 0;

	for (int i = 0; i < str1.length(); ++i)
	{
		if (96 < str1[i] && str1[i] < 123)
			continue;

		else if (64 < str1[i] && str1[i] < 91)
			str1[i] += 32;
		else
		{
			str1.erase(i, 1);
			i--;
		}

	}

	for (int i = 0; i < str2.length(); ++i)
	{
		if (96 < str2[i] && str2[i] < 123)
			continue;

		else if (64 < str2[i] && str2[i] < 91)
			str2[i] += 32;
		else
		{
			str2.erase(i, 1);
			i--;
		}

	}

	for (int i=1; i<str1.length(); ++i)
	{
		string tmp = "";
		
		tmp += str1[i - 1];
		tmp += str1[i];

		set1.push_back(tmp);
		
	}

	for (int i = 1; i<str2.length(); ++i)
	{
		string tmp = "";

		tmp += str2[i - 1];
		tmp += str2[i];

		set2.push_back(tmp);

	}

	answer = function(set1, set2);

	return answer;
}


int main()
{

	string str1 = "FRANCE";
	string str2 = "french";

	cout << solution(str1, str2);

	return 0;
}
/*

str1	str2	answer
FRANCE	french	16384
handshake	shake hands	65536
aa1+aa2	AAAA12	43690
E=M*C^2	e=m*c^2	65536

*/
