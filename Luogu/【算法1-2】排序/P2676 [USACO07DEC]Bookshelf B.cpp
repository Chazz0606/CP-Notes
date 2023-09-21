#include<bits/stdc++.h>

using namespace std;

bool comp(int a, int b){
    return (a > b);
}

int main() {
    int n; int b;
    cin >> n >> b;
    vector<int> cows = {};
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        cows.push_back(temp);
    }

    int height = 0;
    int cnt = 0;
    sort(cows.begin(), cows.end(), comp);
    for (int h: cows){
        height += h;
        cnt++;
        if (height >= b)
            break;
    }

    cout << cnt << endl;

    return 0;
}