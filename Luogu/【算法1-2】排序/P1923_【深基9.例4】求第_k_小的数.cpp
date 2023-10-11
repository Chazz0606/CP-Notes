#include<bits/stdc++.h>

using namespace std;

int find_k_min(vector<int>& nums, int k){ // NOLINT(misc-no-recursion)
    if (static_cast<int>(nums.size()) <= 1)
        return nums[0];
    vector<int> a = {};
    vector<int> b = {};
    int pivot = nums[0];
    int same_cnt = 0;
    for (int i: nums){
        if (i < pivot)
            a.push_back(i);
        else if (i > pivot)
            b.push_back(i);
        else
            same_cnt++;
    }

    if (k < a.size()) {
        nums = a;
    }else if (k < a.size()+same_cnt){
        return pivot;
    }else{
        nums = b;
        k -= static_cast<int>(a.size()) + same_cnt;
    }

    return find_k_min(nums, k);
}

int main() {
    int n; int k;
    cin >> n >> k;
    vector<int> nums = {};
    for (int i = 0; i < n; i++){
        int num = 0;
        cin >> num;
        nums.push_back(num);
    }

//    int n = 100;
//    vector<int> nums = {};
//    default_random_engine e(time(nullptr));
//    for (int i = 0; i < n; i++){
//        nums.push_back(e()%1000);
//    }

    cout << find_k_min(nums, k) << endl;

    return 0;
}