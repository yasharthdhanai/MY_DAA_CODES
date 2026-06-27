#include<bits/stdc++.h>
using namespace std;
    
// Count partition with given diffrence.
// Count subsets with sum k. where k = (total-diff)/2 or (total+diff)/2.
// Same as Lecture 17. Count subsets with sum k.
// There are 2 edge cases : total-diff must be even and total-diff must be positive.

int CountPartition(vector<int>& nums, int diff){
    
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++)
        cin >> nums[i];
    int diff;
    cin >> diff;

    cout << CountPartition(nums, diff) << endl;

    return 0;
}