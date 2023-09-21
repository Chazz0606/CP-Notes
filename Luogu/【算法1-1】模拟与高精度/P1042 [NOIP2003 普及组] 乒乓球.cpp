#include<bits/stdc++.h>

using namespace std;

int main() {
    string t;
    int w_11 = 0; int l_11 = 0;
    int w_21 = 0; int l_21 = 0;

    vector<int[2]> results_11 = {};
    vector<int[2]> results_21 = {};

    do {
        cin >> t;
        for (char result: t){
            if (result == 'W') {
                w_11++;
                w_21++;
            }
            else {
                l_11++;
                l_21++;
            }

            if (w_11 >= 11 && w_11 - l_11 >= 2){
                int scores[2] = {w_11, l_11};
                results_11.push_back(scores);
            }

        }
    }while(t[t.length()]);

    return 0;
}