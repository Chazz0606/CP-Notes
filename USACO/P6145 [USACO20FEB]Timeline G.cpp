#include<bits/stdc++.h>
using namespace std;

const int N = 100005;

struct memory{
    int b = 0, x = 0;
};

int milk_time[N] = {};
vector<memory> out[N] = {};
int in[N] = {};

int main() {
    int n, m, c; cin >> n >> m >> c;
    for (int i = 1; i <= n; i++)
        cin >> milk_time[i];
    for (int i = 0; i < c; i++){
        int a, b, x; cin >> a >> b >> x;
        out[a].push_back({b, x});
        in[b]++;
    }

    queue<int> q = {};
    for (int i = 1; i < n; i++) if (!in[i]) q.push(i);

    while (!q.empty()){
        int x = q.front();
        q.pop();
        for (memory i: out[x]){
            milk_time[i.b] = max(milk_time[i.b], milk_time[x]+i.x);
            in[i.b]--;
            if (!in[i.b]) q.push(i.b);
        }
    }

    for (int i = 1; i <= n; i++)
        cout << milk_time[i] << endl;

//    cout << milk_time[1] << endl;
//    for (int i = 2; i <= n; i++){
//        for (memory j: out[i]) milk_time[i] = max(milk_time[i], milk_time[j.a]+j.x);
//        cout << milk_time[i] << endl;
//    }

    return 0;
}