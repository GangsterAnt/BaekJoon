//https://programmers.co.kr/learn/courses/30/lessons/42577

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;
	sort(phone_book.begin(), phone_book.end());

	for (int i = 1; i < phone_book.size(); ++i)
	{
		string alpha = phone_book[i - 1];	
		string beta = phone_book[i];

		if (alpha.length() > beta.length())
		{// beta 가 길게한다.
			alpha = beta;
			beta = phone_book[i - 1];
		}

		if (beta.find(alpha) == 0)
		{
			return false;
		}
		

	}


	return answer;
}
