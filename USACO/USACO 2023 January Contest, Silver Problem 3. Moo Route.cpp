#pragma clang diagnostic push
#pragma ide diagnostic ignored "bugprone-branch-clone"
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long a[100005];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    string t;
    int dir = 1;
    int current = 0;
    while (a[current] > 0 || (current > 0 && a[current-1] > 0) || (current < n - 1 && a[current+1] > 0)){
        a[current]--;
        t += (dir == 1) ? 'R':'L';

        if (current + dir < 0 || current + dir > n-1)
            dir *= -1;
        else if (a[current+dir] > 1)
            current += dir;
        else if (a[current+dir] <= 1 && a[current] > 1)
            dir *= -1;
        else if (a[current+dir] == 1 && a[current] <= 0)
            current += dir;
        else if (a[current+dir] <= 0 && a[current] == 1)
            dir *= -1;
    }
    cout << t << endl;

    return 0;
}
#pragma clang diagnostic pop