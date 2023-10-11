#include<bits/stdc++.h>
using namespace std;

const int N = 100005;
const int MOD = 1000000007;

struct segment{
    int l = 0;
    int r = 0;
//    int behind_cnt = 0;
};

bool lcmp(segment a, segment b){
    return a.l < b.l;
}

bool rcmp(segment a, segment b){
    return a.r < b.r;
}

//int mod_pow_2(int& power){
//    int res = 1;
//    for (int i = 0; i < power; i++)
//        res = (res << 1) % MOD;
//    return res;
//}

segment segments[N] = {};
segment r_sort_segments[N] = {};

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> segments[i].l >> segments[i].r;
        r_sort_segments[i] = segments[i];
    }
    sort(segments, segments+n, lcmp);
    sort(r_sort_segments, r_sort_segments + n, rcmp);
//    int x = 0;
//    for (int i = 0; i < n; i++){
//        while (r_sort_segments[x].r < segments[i].l && x < n) x++;
//        segments[i].behind_cnt = x;
//    }

//    for (int i = 0; i < n; i++)
//        cout << segments[i].l << ' ' << segments[i].r << ' ' << segments[i].behind_cnt << endl;

    int cnt = 0;
    int mod_pow_2 = 1;
    int x = 0;
    for (int i = 0; i < n; i++) {
        while (r_sort_segments[x].r < segments[i].l) {
            mod_pow_2 = (mod_pow_2 * 2) % MOD;
            x++;
        }
        cnt = ((cnt << 1) % MOD + mod_pow_2) % MOD;
    }
    cout << cnt << endl;

//    int total_cnt = 0;
//    map<int, int[2]> end_cnt = {};
//    for (int i = 0; i < n; i++){
//        int cnt[2] = {1, 1};
//        total_cnt += 1;
//        for (pair<const int, int[2]> j: end_cnt){
//            if (j.first < segments[i].l) {
//                total_cnt += j.second[0] + j.second[1];
//                cnt[0] += j.second[0] + j.second[1];
//                cnt[1] += j.second[1];
//            } else if (segments[i].l < j.first && segments[i].r > j.first) {
//                total_cnt += j.second[0];
//                cnt[0] += j.second[0];
//                cnt[1] += j.second[1];
//            } else {
//                total_cnt += j.second[0];
//                end_cnt[j.first][0] = (end_cnt[j.first][0] * 2) % MOD;
//                end_cnt[j.first][1] = (end_cnt[j.first][1] * 2) % MOD;
//            }
//            total_cnt %= MOD;
//            cnt[0] %= MOD;
//            cnt[1] %= MOD;
//        }
//        end_cnt[segments[i].r][0] = cnt[0];
//        end_cnt[segments[i].r][1] = cnt[1];
//    }
//
//    cout << total_cnt << endl;

    return 0;
}