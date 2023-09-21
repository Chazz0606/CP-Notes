#include<bits/stdc++.h>

using namespace std;

int main() {
    long long n = 0;
    cin >> n;
    map<long long, long long> level_cnt = {};
    for (long long i = 0; i < n; i++){
        long long temp = 0;
        cin >> temp;
        if (level_cnt.count(temp) == 1)
            level_cnt[temp]++;
        else
            level_cnt[temp] = 1;
    }

    vector<long long> maximum = {0, 0};
    map<long long, long long> buy_cnt = {};
    long long last_total_cnt = n;
    long long last_cnt = 0;
    for (pair<long long, long long> level: level_cnt) {
        buy_cnt[level.first] = last_total_cnt - last_cnt;
        long long revenue = level.first * buy_cnt[level.first];
        if (revenue > maximum[0])
            maximum = {revenue, level.first};
        last_cnt = level.second;
        last_total_cnt = buy_cnt[level.first];
    }

    cout << maximum[0] << ' ' << maximum[1] << endl;

    return 0;
}