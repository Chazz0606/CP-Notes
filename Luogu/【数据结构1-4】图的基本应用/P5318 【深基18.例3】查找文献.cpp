#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>& dfs, vector<bool>& dfs_exist, vector<set<int>>& tree, int x){ // NOLINT(misc-no-recursion)
    for (int i: tree[x]){
        if (!dfs_exist[i]) {
            dfs_exist[i] = true;
            dfs.push_back(i);
            solve(dfs, dfs_exist, tree, i);
        }
    }
}

void print_vector(vector<int>& x){
    for (int i: x)
        cout << i << ' ';
    cout << endl;
}

int main() {
    int n, m; cin >> n >> m;
    vector<set<int>> tree = {{}};
    vector<bool> dfs_exist(n+1, false);
    vector<bool> bfs_exist(n+1, false);
    for (int i = 0; i < n; i++)
        tree.emplace_back();
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        tree[a].insert(b);
    }

    vector<int> dfs = {1};
    solve(dfs, dfs_exist, tree, 1);
    print_vector(dfs);

    vector<int> bfs = {1};
    queue<int> q;
    q.push(1);
    while (!q.empty()){
        int x = q.front();
        q.pop();
        for (int i: tree[x]){
            if (!bfs_exist[i]) {
                bfs_exist[i] = true;
                bfs.push_back(i);
                q.push(i);
            }
        }
    }
    print_vector(bfs);

    return 0;
}