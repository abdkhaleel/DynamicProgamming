class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, 0);
        dp[0] = nums[0];
        if (n == 1) return nums[0];
        if (n == 0) return 0;
        int pick, not_pick;
        for(int i = 1; i < n; i++){
            pick = nums[i];
            if (i > 1) pick += dp[i - 2];
            not_pick = 0 + dp[i - 1];
            dp[i] = max(pick, not_pick);
        }
        return dp[n-1];
        
    }
};