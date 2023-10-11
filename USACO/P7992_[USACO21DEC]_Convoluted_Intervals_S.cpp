#include<bits/stdc++.h>
using namespace std;

struct cow;
bool cow_start_comp(const cow& a, const cow& b);
int find(int x);

int n = 0, k = 0;

struct cow{
    int start = 0;
    int end = 0;
    set<int> passed = {};
    int leader = 0;
};

bool cow_start_comp(const cow& a, const cow& b){
    return a.start < b.start;
}

int find(int x, vector<cow>& cows) { // NOLINT(misc-no-recursion)
    if (cows[x].leader == x) {
        return x;
    } else {
        cows[x].leader = find(cows[x].leader, cows);
        return cows[x].leader;
    }
}

int main() {
    cin >> n >> k;
    vector<cow> cows(n);

    for (int i = 0; i < n; i++){
        cows[i].start = i;
        cows[i].leader = i;
        cows[i].passed.insert(i);
    }

    for (int i = 0; i < k; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        swap(cows[a], cows[b]);
        cows[a].passed.insert(a);
        cows[b].passed.insert(b);
    }

    for (int i = 0; i < n; i++)
        cows[i].end = i;
    sort(cows.begin(), cows.end(), cow_start_comp);

    for (int i = 0; i < n; i++) {
        cows[i].leader = find(cows[i].end, cows);
        cows[cows[i].leader].passed.insert(cows[i].passed.begin(), cows[i].passed.end());
    }

    for (int i = 0; i < n; i++)
        cout << cows[cows[i].leader].passed.size() << endl;

    return 0;
}