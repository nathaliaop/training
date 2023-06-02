// https://leetcode.com/problems/maximum-subarray

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
    
        vector<int> dp(n);
        
        int ans = nums[0];
        dp[0] = nums[0];
        
        for (int i = 1; i < n; i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    Solution sol;
    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    cout << sol.maxSubArray(nums) << '\n';

    return 0;
}
