#include<bits/stdc++.h>
using namespace std;

int n = 0, k = 0;

struct cow{
    int start = 0;
    int end = 0;
    map<int, bool> passed = {};
};

bool cow_start_comp(const cow& a, const cow& b){
    return a.start < b.start;
}

int main() {
    cin >> n >> k;

    vector<cow> round_change(n);
    for (int i = 0; i < n; i++){
        round_change[i].start = i;
        for (int j = 0; j < n; j++)
            round_change[i].passed[j] = false;
        round_change[i].passed[i] = true;
    }

    for (int i = 0; i < k; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        swap(round_change[a], round_change[b]);
        if (!round_change[a].passed[a])
            round_change[a].passed[a] = true;
        if (!round_change[b].passed[b])
            round_change[b].passed[b] = true;
    }

    for (int i = 0; i < n; i++)
        round_change[i].end = i;
    sort(round_change.begin(), round_change.end(), cow_start_comp);

    for (int i = 0; i < n; i++){
        map<int, bool> passed = {};
        for (int j = 0; j < n; j++)
            passed[j] = false;
        passed[i] = true;

        map<int, bool> past_round_starts = {};
        for (int j = 0; j < n; j++)
            past_round_starts[j] = false;
        past_round_starts[i] = true;

        int current = i;
        while (true){
            for (int j = 0; j < n; j++)
                passed[j] = passed[j] || round_change[current].passed[j];
            if (past_round_starts[round_change[current].end])
                break;
            else
                current = round_change[current].end;
        }
        int cnt = 0;
        for (int j = 0; j < n; j++)
            cnt += passed[j];
        cout << cnt << endl;
    }

    return 0;
}