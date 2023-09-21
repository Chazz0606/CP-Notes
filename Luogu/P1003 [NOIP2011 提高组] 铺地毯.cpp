#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int arr[n][4];
    for (int i = 0; i < n; i++)
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3];
    int x, y; cin >> x >> y;
    int res = -1;
    for (int i = 0; i < n; i++)
        if (x >= arr[i][0] && y >= arr[i][1] && x <= arr[i][0]+arr[i][2] && y <= arr[i][1]+arr[i][3])
            res = i + 1;
    cout << res << endl;

    return 0;
}