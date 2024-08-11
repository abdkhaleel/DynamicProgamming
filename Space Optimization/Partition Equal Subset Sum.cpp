class Solution {
public:
    // bool f(vector<int>& nums, int ind, int t, vector<vector<int>>& dp){
    //     if(ind == 0) return t == nums[ind];
    //     if(t == 0) return true;
    //     if(dp[ind][t] != -1) return dp[ind][t];
    //     bool notTake = f(nums, ind-1, t, dp);
    //     bool take = false;
    //     if(nums[ind] <= t) take = f(nums, ind-1, t-nums[ind], dp);
    //     return dp[ind][t] = take || notTake;
    // }
    bool canPartition(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }
        if(sum & 1) return false;
        sum /= 2;
        // vector<vector<bool>> dp(n, vector<bool>(sum+1, false));
        vector<bool> prev(sum+1, false);
        for(int i = 0; i < n; i++) prev[0] = true;
        if(nums[0] <= sum) prev[nums[0]] = true;
        for(int ind = 1; ind < n; ind++){
            vector<bool> curr(sum+1, false);
            for(int target = 1; target <= sum; target++){
                bool notTake = prev[target];
                bool take = false;
                if(nums[ind] <= target) take = prev[target-nums[ind]];
                curr[target] = take || notTake;
            }
            prev = curr;
        }
        return prev[sum];
    }
};
