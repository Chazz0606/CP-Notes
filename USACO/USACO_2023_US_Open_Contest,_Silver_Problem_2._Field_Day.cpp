#include<bits/stdc++.h>
using namespace std;

int main() {
    int c, n; cin >> c >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        int x = 0;
        for (int j = 0; j < c; j++){
            char temp; cin >> temp;
            x = (x << 1) + (temp == 'G');
        }
        arr[i] = x;
    }

    for (int i = 0; i < n; i++){
        int maxd = 0;
        for (int j = 0; j < n; j++){
            bitset<18> d = arr[i]^arr[j];
            maxd = max(maxd, (int)(d.count()));
        }
        cout << maxd << endl;
    }

    return 0;
}