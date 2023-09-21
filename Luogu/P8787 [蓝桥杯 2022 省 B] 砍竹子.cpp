#include<bits/stdc++.h>
using namespace std;

//struct interval{
//    int l; int r;
//};

int cut(int a){
    return floor(sqrt(a/2+1));
}

int main() {
    int n; cin >> n;
    long long h[200002] = {};
    for (int i = 0; i < n; i++)
        cin >> h[i];

    bool flag = true;
    while (flag){
        for (int i = 0; i < n; i++){
            int l_val = (i > 0) ? (int) h[i-1]: (int) -INFINITY;
            int r_val = (i < n-1) ? (int) h[i+1]: (int) -INFINITY;
            while (h[i] > l_val && h[i] > r_val && h[i] > 1){
                flag
            }
        }
    }
//    queue<interval> q = {};
//    q.push({0, n});
//    while (!q.empty()){
//        interval x = q.front();
//        q.pop();
//        for (int i = x.l; i < x.r; i++){
//
//        }
//    }

    cout << endl;

    return 0;
}