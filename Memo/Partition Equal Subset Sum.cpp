class Solution {
public:
    bool f(vector<int>& nums, int ind, int t, vector<vector<int>>& dp){
        if(ind == 0) return t == nums[ind];
        if(t == 0) return true;
        if(dp[ind][t] != -1) return dp[ind][t];
        bool notTake = f(nums, ind-1, t, dp);
        bool take = false;
        if(nums[ind] <= t) take = f(nums, ind-1, t-nums[ind], dp);
        return dp[ind][t] = take || notTake;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }
        if(sum & 1) return false;
        sum /= 2;
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        return f(nums, n-1, sum, dp);
    }
};
