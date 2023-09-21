#include<bits/stdc++.h>
using namespace std;

struct node{
    int l = 0;
    int r = 0;
};

vector<node> heap = {};
int find(int x){ // NOLINT(misc-no-recursion)
    if (x == -1)
        return 0;
    return max(find(heap[x].l), find(heap[x].r))+1;
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        heap.emplace_back();
        cin >> heap[i].l >> heap[i].r;
        heap[i].l--; heap[i].r--;
    }

    cout << find(0);

    return 0;
}