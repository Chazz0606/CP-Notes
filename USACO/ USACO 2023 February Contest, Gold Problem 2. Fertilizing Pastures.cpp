#include<bits/stdc++.h>
using namespace std;

const int N = 200005;
int a[N] = {};
vector<int> road[N] = {};
bool t = true;

vector<int> drop(vector<int> v, int index){
    v.erase(v.begin()+index);
    return v;
}

int get_min_fertilizer(vector<int> lst, const vector<vector<int>>& branches, map<vector<int>, int>& memo){ // NOLINT(misc-no-recursion)
    if (lst.size() == 1) return 0;
    else if (lst.size() == 2) return min(branches[lst[0]][2]+(branches[lst[0]][0]+1)*branches[lst[1]][2], branches[lst[1]][2]+(branches[lst[1]][0]+1)*branches[lst[0]][2]);
    if (memo.count(lst)) return memo[lst];
    int minf = INFINITY;
    for (int i: lst){
        vector<int> dropped = drop(lst, i);
        int temp = branches[lst[i]][0]*get_min_fertilizer(dropped, branches, memo);
        minf = min(minf, temp);
        memo[dropped] = temp;
    }
    return minf;
}

vector<int> find(int x){ // NOLINT(misc-no-recursion)
    if (road[x].empty()) return {0, a[x], a[x]};
    vector<vector<int>> branches = {};
    for (int i: road[x])
        branches.push_back(find(i));

    vector<int> res = {(int) branches.size()*2, a[x], a[x]};
    map<vector<int>, int> memo = {};
    for (vector<int>& branch : branches){
        res[0] += branch[0];
        res[1] += branch[1];
        res[2] += branch[2];
    }
    vector<int> lst = {};
    for (int i = 0; i < branches.size(); i++) lst.push_back(i);
    res[1] += get_min_fertilizer(lst, branches, memo);

    return res;
}

int main() {
    int n; cin >> n >> t; t = !t;
    for (int i = 2; i <= n; i++){
        int p = 0;
        cin >> p >> a[i];
        road[p].push_back(i);
    }
    vector<int> result = find(1);
    cout << result[0] << ' ' << result[1] << endl;

    return 0;
}