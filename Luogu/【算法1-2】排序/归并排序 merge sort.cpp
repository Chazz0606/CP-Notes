#include<bits/stdc++.h>

using namespace std;

vector<int> merge_sort(vector<int> nums){ // NOLINT(misc-no-recursion)
    int size = static_cast<int>(nums.size());
    if (size <= 1)
        return nums;
    vector<int> a (nums.begin(), nums.begin()+size/2);
    vector<int> b (nums.begin()+size/2, nums.end());
    a = merge_sort(a);
    b = merge_sort(b);
    vector<int> c = {};
    while (!a.empty() && !b.empty()){
        if (a[0] <= b[0]){
            c.push_back(a[0]);
            a.erase(a.begin());
        }else{
            c.push_back(b[0]);
            b.erase(b.begin());
        }
        if (a.empty())
            c.insert(c.end(), b.begin(), b.end());
        else if (b.empty())
            c.insert(c.end(), a.begin(), a.end());
    }

    return c;
}

int main() {
    int n;
    cin >> n;
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

    nums = merge_sort(nums);
    for (int num: nums)
        cout << num << ' ';

    return 0;
}