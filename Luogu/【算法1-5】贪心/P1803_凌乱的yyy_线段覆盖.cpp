#include<bits/stdc++.h>

using namespace std;

struct competition;
bool competition_comp(competition a, competition b);

struct competition{
    long long start = 1;
    long long end = 0;
};

bool competition_comp(competition a, competition b){
    return a.end < b.end;
}

int main() {
    long long n = 0;
    cin >> n;

    vector<competition> competitions = {};
    for (long long i = 0; i < n; i++){
        competitions.emplace_back();
        cin >> competitions[i].start >> competitions[i].end;
    }
    sort(competitions.begin(), competitions.end(), competition_comp);

    long long cnt = 0;
    long long current_time = 0;
    for (long long i = 0; i < n; i++){
        if (competitions[i].start >= current_time) {
            current_time = competitions[i].end;
            cnt++;
        }
    }
    cout << cnt;

    return 0;
}