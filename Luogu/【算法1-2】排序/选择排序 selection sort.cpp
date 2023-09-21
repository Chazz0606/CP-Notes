#include<bits/stdc++.h>

using namespace std;

vector<int> selection_sort(vector<int> nums){
    for (int i = 0; i < static_cast<int>(nums.size()); i++){
        int min = i;
        for (int j = i + 1; j < static_cast<int>(nums.size()); j++){
            if (nums[j] < nums[min])
                min = j;
        }
        swap(nums[i], nums[min]);
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
    nums = selection_sort(nums);
    for (int i = 0; i < n; i++)
        cout << nums[i] << ' ';

    return 0;
}