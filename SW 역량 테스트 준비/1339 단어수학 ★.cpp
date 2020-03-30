#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

/*
		time out..  first time i made it with pass by value so switch to pass by ref
		however meaningless.
		becasue of line 26
		O(  all char of vector<string> * letters.size() )
*/
int cal2(const vector<string>& s, vector<int>& numbers, vector<char>& letters)
{
	int ret = 0;
	int temp = 0;
	for (int i = 0; i< s.size(); ++i)		//string vector 에서 string s[i] 고르자
	{
		for (int j = 0; j < s[i].length(); ++j)//string s[i] 에서 글자 s[i][j]를 고르자
		{
			for (int k = 0; k < letters.size(); ++k)// 글자 s[i][j] 를 숫자로 바꾸자
			{

				if (s[i][j] == letters[k])	//we have to search fully with O(letters.size() for each double for loop
				{
					temp *= 10;
					temp += numbers[k];
				}
			}	// single letter is swithced to 1 digit
		} //single string is swithced to int
		ret += temp;		//add ret to one 
		temp = 0;
	}

	return ret == 0 ? -1:ret;
}

// O ( Number of characters in every string in vector <string>
int cal(const vector<string>& s, vector<int>& numbers, vector<char>& letters)
{
	char space[256];	// 256개의 char 배열... (1 byte = 256 bit) 알파벳 letters[i] 를 index 로 숫자 저장..
	int ret = 0;		// time space trade off;
	int temp = 0;

	for (int i = 0; i < letters.size(); ++i)
		space[letters[i]] = numbers[i];
	// char 에 int 형을 넣는것에 주의

	for (int i = 0; i< s.size(); ++i)		//string vector 에서 string s[i] 고르자
	{
		for (int j = 0; j < s[i].length(); ++j)//string s[i] 에서 글자 s[i][j]를 고르자
		{
			temp *= 10;
			temp += space[s[i][j]];		//space 는 1 byte char 이지만... 대입을 int 형을 받아서 10 int로 처리해도 괜찮다.
										// numers 의 각 원소는 모두 1 digit 이기때문에 overflow 고려 X
		} //single string is swithced to int
		ret += temp;		//add ret to one 
		temp = 0;
	}

	return ret == 0 ? -1 : ret;
}

int main()
{
	vector <string> v; //string 저장소
	vector <char> letters = vector<char>(0, 0);	// char 저장소
	vector < int > numbers = vector<int>(0, 0);

	int n =0;
	cin >> n;
	
	v = vector<string>(n);	//n 개 초기화.

	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
		for (char X : v[i])	// range based for loop
			letters.push_back(X);
	}

	sort(letters.begin(), letters.end());
	letters.erase(unique(letters.begin(), letters.end()), letters.end());
	int size = letters.size();

	for (int i = 0; i < size; ++i)
		numbers.push_back(9 - i);
	
	sort(numbers.begin(), numbers.end());
	int ans = -1;
	do
	{
		int temp = 0;

		temp = cal(v, numbers, letters);
		ans = max(ans, temp);

		
	} while (next_permutation(numbers.begin(), numbers.end()));


	cout << ans << '\n';
	return 0;
}
