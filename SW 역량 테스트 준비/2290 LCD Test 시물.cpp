// 노가다라서 

#include <iostream>
#include <string>
using namespace std;
int c[10][10]={
    {1,1,1,0,1,1,1},
    {0,0,1,0,0,1,0},
    {1,0,1,1,1,0,1},
    {1,0,1,1,0,1,1},
    {0,1,1,1,0,1,0},
    {1,1,0,1,0,1,1},
    {1,1,0,1,1,1,1},
    {1,0,1,0,0,1,0},
    {1,1,1,1,1,1,1},
    {1,1,1,1,0,1,1}
};
int main() {
    int s;
    string n;
    cin >> s >> n;
    int m = n.length();
    for (int i=0; i<5; i++) {
        if (i == 0 || i == 2 || i == 4) {
            for (int j=0; j<m; j++) {
                int now = n[j]-'0';
                if (j != 0) {
                    cout << ' ';
                }
                cout << ' ';
                if ((i == 0 && c[now][0]) || (i == 2 && c[now][3]) || (i == 4 && c[now][6])) {
                    for (int k=0; k<s; k++) {
                        cout << '-';
                    }
                } else {
                    for (int k=0; k<s; k++) {
                        cout << ' ';
                    }
                }
                cout << ' ';
            }
            cout << '\n';
        } else {
            for (int l=0; l<s; l++) {
                for (int j=0; j<m; j++) {
                    int now = n[j] - '0';
                    if (j != 0) {
                        cout << ' ';
                    }
                    if ((i == 1 && c[now][1]) || (i == 3 && c[now][4])) {
                        cout << '|';
                    } else {
                        cout << ' ';
                    }
                    for (int k=0; k<s; k++) {
                        cout << ' ';
                    }
                    if ((i == 1 && c[now][2]) || (i == 3 && c[now][5])) {
                        cout << '|';
                    } else {
                        cout << ' ';
                    }
                }
                cout << '\n';
            }
        }
    }
    return 0;
}
