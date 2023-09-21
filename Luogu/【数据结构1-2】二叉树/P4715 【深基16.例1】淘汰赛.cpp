#include<bits/stdc++.h>
using namespace std;

struct team{
    int id = 0;
    int power = 0;
};

bool cmp(team a, team b){
    return a.power < b.power;
}

int main() {
    int n; cin >> n;
    team heap[10005] = {};
    for (int i = 0; i < pow(2, n); i++) {
        int temp = 0;
        cin >> temp;
        heap[(int) pow(2, n)+i-1] = (team){i+1, temp};
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < pow(2, n-i-1); j++) {
            heap[(int) pow(2, n-i-1)-1+j] = max(heap[(int) pow(2, n-i)+2*j-1], heap[(int) pow(2, n-i)+2*j], cmp);
        }
    }

    cout << min(heap[1], heap[2], cmp).id;

    return 0;
}