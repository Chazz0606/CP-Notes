#include<bits/stdc++.h>
using namespace std;
#define N 100005

void quick_sort(int nums[], int left, int right){ // NOLINT(misc-no-recursion)
    if (right-left <= 1)
        return;
    int pivot = nums[left];
    int index = left;
    for (int i = left+1; i < right; i++) if (nums[i] < pivot) swap(nums[++index], nums[i]);
    swap(nums[left], nums[index]);

    quick_sort(nums, left, index);
    quick_sort(nums, index+1, right);
}

int main() {
    int n;
    cin >> n;
    int nums[N] = {};
    for (int i = 0; i < n; i++) cin >> nums[i];

    quick_sort(nums, 0, n);
    for (int i = 0; i < n; i++)
        cout << nums[i] << ' ';

    return 0;
}