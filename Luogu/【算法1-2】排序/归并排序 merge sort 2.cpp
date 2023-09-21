#include<bits/stdc++.h>
using namespace std;
#define N 10005

void merge_sort(int nums[], int sorted[], int l, int r){ // NOLINT(misc-no-recursion)
    if (l == r) {
        sorted[0] = nums[l];
        return;
    }
    int mid = (l + r) >> 1;
    int a[N] = {};
    merge_sort(nums, a, l, mid);
    int b[N] = {};
    merge_sort(nums, b, mid+1, r);
    int i = 0, j = 0, k = 0;
    while (j < mid-l+1 && k < r-mid){
        if (a[j] < b[k]) sorted[i++] = a[j++];
        else sorted[i++] = b[k++];
    }
    while (j < mid-l+1) sorted[i++] = a[j++];
    while (k < r-mid) sorted[i++] = b[k++];
}

int main() {
    int n; cin >> n;
    int nums[N] = {};
    for (int i = 0; i < n; i++) cin >> nums[i];

//    int n = 100;
//    int nums[N] = {};
//    default_random_engine e(time(nullptr));
//    for (int i = 0; i < n; i++){
//        nums[i] = e()%1000;
//    }

    int sorted[N] = {};
    merge_sort(nums, sorted, 0, n-1);
    for (int i = 0; i < n; i++)
        cout << sorted[i] << ' ';

    return 0;
}