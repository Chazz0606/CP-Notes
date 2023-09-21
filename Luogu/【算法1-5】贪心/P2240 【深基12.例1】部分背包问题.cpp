#include<bits/stdc++.h>

using namespace std;

struct pile;
bool pile_comp(pile a, pile b);

struct pile{
    int mass = 0;
    int value = 1;
    double unit_value = 0;
};

bool pile_comp(pile a, pile b){
    return a.unit_value > b.unit_value;
}

int main() {
    int N = 0; int T = 0;
    cin >> N >> T;

    vector<pile> piles = {};
    for (int i = 0; i < N; i++){
        piles.emplace_back();
        cin >> piles[i].mass >> piles[i].value;
        piles[i].unit_value = (double) piles[i].value/ (double) piles[i].mass;
    }
    sort(piles.begin(), piles.end(), pile_comp);

    double max_value = 0;
    for (int i = 0; i < N; i++){
        if (T >= piles[i].mass) {
            max_value += piles[i].value;
            T -= piles[i].mass;
        } else {
            max_value += T * piles[i].unit_value;
            break;
        }
    }

    printf("%.2lf\n", max_value);

    return 0;
}