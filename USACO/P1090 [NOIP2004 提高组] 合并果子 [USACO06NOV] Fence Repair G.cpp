#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    priority_queue<int, vector<int>, greater<>> heaps = {};

    for (int i = 0; i < n; i++){
        int temp; cin >> temp;
        heaps.push(temp);
    }

    int sum = 0;
    for (int i = 0; i < n-1; i++){
        int a = heaps.top(); heaps.pop();
        int b = heaps.top(); heaps.pop();
        sum += a + b;
        heaps.push(a+b);
    }

    cout << sum << endl;

    return 0;
}