#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums = {};
    for (int i = 0; i < n; i++){
        int num = 0;
        cin >> num;
        nums.push_back(num);
    }

    sort(nums.begin(), nums.end());
    int i = 1;
    while (i < nums.size()){
        if (nums[i] == nums[i-1])
            nums.erase(nums.begin()+i);
        else
            i++;
    }

    int m = static_cast<int>(nums.size());
    cout << m << endl;
    for (int j = 0; j < m; j++)
        cout << nums[j] << ' ';

    return 0;
}