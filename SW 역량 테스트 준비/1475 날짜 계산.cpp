#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int esm[16][29][20];	//15 28 19

	for (int i = 1; i <= 7980; ++i)
	{
		int a, b, c;
		a = b = c = i;

		while (a >= 16)
			a -= 15;
		while (b >= 29)
			b -= 28;
		while (c >= 20)
			c -= 19;

		esm[a][b][c] = i;
		//cout << "esm [" << a << "][" << b << "][" << c << "] = " << " " << esm[a][b][c] << '\n';
	}

	int e, s, m;
	cin >> e >> s >> m;

	cout << esm[e][s][m]<<'\n';

	
	return 0;
}
