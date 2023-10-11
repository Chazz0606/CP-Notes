#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> piles = {};
    int n; cin >> n;
    int max_plate = 0;
    for (int i = 1; i <= n; i++){
        int num; cin >> num;

        if (piles.empty() || num > piles.back().front()){
            piles.push_back({num});
            continue;
        }
        if (num < max_plate) {
            cout << i - 1 << endl;
            return 0;
        }

        int l = 0; int r = static_cast<int>(piles.size());
        while (l < r){
            int mid = (l+r)/2;
            if (num < piles[mid].front())
                r = mid;
            else
                l = mid + 1;
        }

        while (num > piles[l].back()){
            max_plate = piles[l].back();
            piles[l].pop_back();
        }
        piles[l].push_back(num);
    }

    cout << n << endl;

    return 0;
}