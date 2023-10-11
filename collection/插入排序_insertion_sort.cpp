#include<bits/stdc++.h>
using namespace std;

vector<int> insertion_sort(vector<int> nums){
    for (int i = 1; i < static_cast<int>(nums.size()); i++){
        int num = nums[i];
        nums.erase(nums.begin()+i);
        bool found = false;
        if (num >= nums[i-1]){
            nums.insert(nums.begin()+i, num);
            found = true;
        }
        for (int j = i - 1; j > 0; j--){
            if (num >= nums[j - 1] && num <= nums[j] && !found){
                nums.insert(nums.begin()+j, num);
                found = true;
                break;
            }
        }
        if (!found)
            nums.insert(nums.begin(), num);
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

//    int n = 100;
//    vector<int> nums = {};
//    default_random_engine e(time(nullptr));
//    for (int i = 0; i < n; i++){
//        nums.push_back(e()%1000);
//    }

    nums = insertion_sort(nums);
    for (int i = 0; i < n; i++)
        cout << nums[i] << ' ';

    return 0;
}