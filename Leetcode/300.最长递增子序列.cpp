#include<bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    vector<int> dp = {1};
    for (int i = 1; i < nums.size(); i++){
        int a = 0;
        for (int j = 0; j < i; j++){
            if (nums[j] < nums[i])
                a = max(a, dp[j]);
        }
        dp.push_back(max(a+1, dp[i-1]));
    }
    return dp[dp.size()-1];
}

int main() {
    vector<int> nums = {10,9,2,5,3,7,101,18};
    cout << lengthOfLIS(nums) << endl;

    return 0;
}