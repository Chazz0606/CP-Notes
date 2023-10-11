#include<bits/stdc++.h>
using namespace std;

const int N = 1000010;
long long nums[N], a[N], b[N];

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> nums[i];

    a[1] = nums[1];
    for (int i = 2; i <= n; i++) a[i] = max(a[i - 1] + nums[i], nums[i]); // 以i结尾的最大和子串
    for (int i = 2; i <= n; i++) a[i] = max(a[i - 1], a[i]); // i以前的最大和子串，不一定以i结尾

    b[n] = nums[n];
    for (int i = n-1; i >= 1; i--) b[i] = max(b[i + 1] + nums[i], nums[i]); // 以i开始的最大和子串
    for (int i = n-1; i >= 1; i--) b[i] = max(b[i + 1], b[i]); // i以后的最大和子串，不一定以i开始

    long long maxs = a[1]+b[3];
    for (int i = 3; i <= n-1; i++) maxs = max(maxs, a[i-1] + b[i+1]);
    cout << maxs << endl;

    return 0;
}