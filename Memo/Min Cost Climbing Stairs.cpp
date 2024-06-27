class Solution {
public:
    int f(vector<int>& cost, int i, vector<int>& dp){
        if(i < 0) return 1e9;
        if(i == 1) return cost[1];
        if(i == 0) return cost[0];
        if(dp[i] != -1) return dp[i];
        int single_step = cost[i] + f(cost, i-1, dp);
        int double_step = cost[i] + f(cost, i-2, dp);

        return dp[i] = min(single_step, double_step);

    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n,-1);
        return min(f(cost, n-1, dp), f(cost, n-2, dp));        
    }
};