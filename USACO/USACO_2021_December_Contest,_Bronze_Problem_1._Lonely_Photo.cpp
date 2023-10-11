#include<bits/stdc++.h>

using namespace std;

int main() {
    int n = 0;
    cin >> n;
    string t;
    cin >> t;

    long long int cnt = 0;
    for (int i = 0; i < n; i++){
        int g_cnt = 0;
        int h_cnt = 0;
        for (int j = i; j < n; j++){
            if (t[j] == 'G')
                g_cnt += 1;
            else
                h_cnt += 1;

            if (g_cnt >= 2 and h_cnt >= 2)
                break;

            if (j - i >= 2 and (g_cnt == 1 or h_cnt == 1)){
                cnt += 1;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}