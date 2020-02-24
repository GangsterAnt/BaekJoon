//https://www.acmicpc.net/problem/9019
//
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
#include <string>
#include <map>

using namespace std;

vector<char> order;
map< int, string > tosort;
bool visited[10000];

int rotateL(int in)
{
	int a, b, c, d;
	a = in / 1000;
	b = in / 100 - a * 10;
	c = in / 10 - a * 100 - b * 10;
	d = in % 10;


	int out = b * 1000 + c * 100 + d * 10 + a;

	return out;
}
int rotateR(int in)
{
	int a, b, c, d;
	a = in / 1000;
	b = in / 100 - a * 10;
	c = in / 10 - a * 100 - b * 10;
	d = in % 10;


	int out = d * 1000 + a * 100 + b * 10 + c;;

	return out;
}

void bfs(int start, int fin);

int main()
{
	int c;
	cin >> c;

	while (c--)
	{
		int start, fin;
		cin >> start >> fin;

		tosort.clear();
		memset(visited, false, sizeof(visited));

		bfs(start, fin);
		
		/*cout << "Graph is Done\n";
		map<int, char> ::iterator iter;
		for (iter = tosort.begin(); iter != tosort.end(); iter++)
		cout << "[" << iter->first << " , " << iter->second << " ]  \n";*/
	
		//cout << tosort[fin] << '\n';
	}

	return 0;
}


void bfs(int start, int fin)
{
	

	queue<pair< int,string>> q;
	q.push(make_pair(start,""));
	visited[start] = true;

	while (!q.empty())
	{
		const int here = q.front().first;
		string words = q.front().second;
		q.pop();
		int temp;

		if (here == fin)
		{
			cout << words << '\n';
			return;
		}

		//D
			temp = (here * 2 % 10000);

			if (!visited[temp])
			{
				visited[temp] = true;
				q.push(make_pair(temp, words + "D"));

			}

			//S

			//temp = (here - 1) < 0 ? 9999 : here - 1;
			if (here == 0)
				temp = 9999;

			else
				temp = here - 1;
			if (!visited[temp])
			{
				visited[temp] = true;
				q.push(make_pair(temp, words + "S"));

			

			}

			//L
			temp = rotateL(here);
			if (!visited[temp])
			{
				visited[temp] = true;
				q.push(make_pair(temp, words + "L"));

			
			}

			//R
			temp = rotateR(here);
			if (!visited[temp])
			{
				visited[temp] = true;
				q.push(make_pair(temp, words + "R"));

				
			}
		
	}
}
