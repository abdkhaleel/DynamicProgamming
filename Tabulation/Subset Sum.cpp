class Solution{   
public:
    // bool f(int ind, int sum, vector<int>& arr, vector<vector<int>>& dp){
    //     if(sum == 0) return true;
    //     if(ind == 0) return arr[ind] == sum;
    //     if(dp[ind][sum] != -1) return dp[ind][sum];
    //     bool notTake = f(ind-1, sum, arr, dp);
    //     bool take = false;
    //     if(arr[ind] <= sum) take = f(ind-1, sum-arr[ind], arr, dp);
    //     return dp[ind][sum] = take | notTake;
    // }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));
        for(int i = 0; i < n; i++){
            dp[i][0] = true;
        }
        if(arr[0] <= sum){
            dp[0][arr[0]] = true;
        }
        for(int ind = 1; ind < n; ind++){
            for(int target = 1; target <= sum; target++){
                bool notTake = dp[ind-1][target];
                bool take = false;
                if(arr[ind] <= target){
                    take = dp[ind-1][target-arr[ind]];
                }
                dp[ind][target] = take || notTake;
                
            }
        }
        return dp[n-1][sum];
    }
};
