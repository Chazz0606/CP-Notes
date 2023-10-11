#include<bits/stdc++.h>

using namespace std;

vector<int> bucket_sort(vector<int>& nums){ // NOLINT(misc-no-recursion)
    const int bucket_size = 10;
    const int maximum = 1000;
    int size = static_cast<int>(nums.size());
    vector<vector<int>> buckets = {};
    for (int i = 0; i < maximum/bucket_size; i++)
        buckets.emplace_back();

    for (int num: nums)
        buckets[num/bucket_size].push_back(num);

    for (vector<int> bucket: buckets){
        for
    }

    return a;
}

int main() {
//    int n;
//    cin >> n;
//    vector<int> nums = {};
//    for (int i = 0; i < n; i++){
//        int num = 0;
//        cin >> num;
//        nums.push_back(num);
//    }

    int n = 100;
    vector<int> nums = {};
    default_random_engine e(time(nullptr));
    for (int i = 0; i < n; i++){
        nums.push_back(e()%1000);
    }

    nums = bucket_sort(nums);
    for (int num: nums)
        cout << num << ' ';

    return 0;
}