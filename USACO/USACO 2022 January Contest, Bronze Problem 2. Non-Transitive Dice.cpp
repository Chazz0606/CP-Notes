#include<bits/stdc++.h>

using namespace std;

int find_larger(int a, int b){
    if (a > b)
        return 1;
    else if (a == b)
        return 0;
    else
        return -1;
}

int find_winner(const int a[4], const int b[4]){
    int win_cnt = 0;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            win_cnt += find_larger(a[i], b[i]);
        }
    }

    if (win_cnt > 0)
        return 0;
    else if (win_cnt == 0)
        return 1;
    else
        return 2;
}

int main() {
    int n = 0;
    cin >> n;
    for (int repeat = 0; repeat < n; repeat++) {
        int a_die[4];
        int b_die[4];

        for (int &i: a_die)
            cin >> i;

        for (int &i: b_die)
            cin >> i;

        int winner = find_winner(a_die, b_die);
        if (winner == 2){
            for (int i = 0; i < 4; i++){
                int temp = a_die[i];
                a_die[i] = b_die[i];
                b_die[i] = temp;
            }
        }else if (winner == 1){
            cout << "no" << endl;
            break;
        }

        bool flag = false;
        for (int a = 1; a <= 10; a++){
            for (int b = 1; b <= 10; b++){
                for (int c = 1; c <= 10; c++){
                    for (int d = 1; d <= 10; d++){
                        int c_die[4] = {a, b, c, d};
                        if (a == 1 && b == 4 && c == 8 && d == 9 && repeat == 0)
                            cout << "aaaa" << endl;

                        if ((find_winner(c_die, a_die) == 0) && (find_winner(b_die, c_die) == 0)){
                            flag = true;
                            break;
                        }
                    }
                    if (flag)
                        break;
                }
                if (flag)
                    break;
            }
            if (flag)
                break;
        }
        if (flag)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }

    return 0;
}
