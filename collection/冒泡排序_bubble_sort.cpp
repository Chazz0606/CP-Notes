#include<bits/stdc++.h>

using namespace std;

vector<int> bubble_sort(vector<int> nums){
    int end = static_cast<int>(nums.size()) - 1;
    int i = 0;
    while (i < end){
        if (nums[i] > nums[i+1])
            swap(nums[i], nums[i+1]);
        if (i + 1 == end) {
            i = 0;
            end--;
        }else{
            i++;
        }
    }
    return nums;
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
    nums = bubble_sort(nums);
    for (int i = 0; i < n; i++)
        cout << nums[i] << ' ';

    return 0;
}