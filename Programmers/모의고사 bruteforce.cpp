//https://programmers.co.kr/learn/courses/30/lessons/42840
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	int index = 0;
	int size = answers.size();
	int score1=0, score2=0, score3=0;
	string s1 = "12345";
	string s2 = "21232425";
	string s3 = "3311224455";

	for (int i = 0; i<size; ++i)
	{
		if (answers[i] == s1[i % s1.length()] - '0')
			score1++;

		if (answers[i] == s2[i % s2.length()] - '0')
			score2++;

		if (answers[i] == s3[i % s3.length()] - '0')
			score3++;
	}
    cout<<score1<<' '<<score2<<' '<<score3<<'\n';
	int m = max ( score3, max(score1, score2));
    cout<<m<<'\n';
	if (m == score1)
		answer.push_back(1);
	if (m == score2)
		answer.push_back(2);
	if (m == score3)
		answer.push_back(3);

	return answer;
}
