#include<bits/stdc++.h>
using namespace std;

int main() {
    int l, n; cin >> l >> n;
    int arr[n];
    int maxc = 0;
    int maxo = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        maxc = max(maxc, min(arr[i], (l+1)-arr[i]));
        maxo = max(maxo, max(arr[i], (l+1)-arr[i]));
    }
    cout << maxc << ' ' << maxo << endl;

    return 0;
}