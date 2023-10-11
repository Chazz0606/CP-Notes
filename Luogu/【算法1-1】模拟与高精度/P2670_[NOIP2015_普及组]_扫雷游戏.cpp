#include<bits/stdc++.h>

using namespace std;

int main() {
    int temp1; int temp2;
    cin >> temp1 >> temp2;
    const int n = temp1;
    const int m = temp2;

    int board[n][m];
    for (int i = 0; i < n; i++){
        string line;
        cin >> line;
        for (int j = 0; j < m; j++){
            board[i][j] = line[j] == '*' ? -1: 0;
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (board[i][j] == -1){
                for (int a = -1; a <= 1; a++){
                    for (int b = -1; b <= 1; b++){
                        if (!(i + a < 0 or i + a >= n) and !(j + b < 0 or j + b >= m) and board[i+a][j+b] != -1){
                            board[i+a][j+b]++;
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            char prt;
            if (board[i][j] == -1)
                prt = '*';
            else
                prt = static_cast<char>(board[i][j]+48);
            cout << prt;
        }
        cout << endl;
    }

    return 0;
}