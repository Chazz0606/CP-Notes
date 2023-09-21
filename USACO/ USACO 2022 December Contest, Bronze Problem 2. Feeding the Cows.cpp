#include<bits/stdc++.h>

using namespace std;

int main() {
    int t = 0;
    cin >> t;
    for (int x = 0; x < t; x++){
        int n = 0; int k = 0;
        cin >> n >> k;
        vector<char> cows = {};
        for (int i = 0; i < n; i++){
            cows.emplace_back();
            cin >> cows[i];
        }

        map<char, int> last = {{'G', -k-1}, {'H', -k-1}};

        vector<char> patches(n, '.');
        int patch_cnt = 0;
        for (int i = 0; i < n; i++){
            if (abs(i - last[cows[i]]) > k){
                patch_cnt++;
                int target = i + k;
                if (target >= cows.size())
                    target = static_cast<int>(cows.size())-1;
                for (int j = target; j >= i - k; j--){
                    if (patches[j] == '.') {
                        patches[j] = cows[i];
                        last[cows[i]] = j;
                        break;
                    }
                }
            }
        }

        cout << patch_cnt << endl;
        for (char patch : patches)
            cout << patch;
        cout << endl;
    }


    return 0;
}