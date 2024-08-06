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
        // vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));
        // for(int i = 0; i < n; i++){
        //     dp[i][0] = true;
        // }
        vector<bool> prev(sum + 1, false);
        prev[0] = true;
        if(arr[0] <= sum){
            prev[arr[0]] = true;
        }
        for(int ind = 1; ind < n; ind++){
            vector<bool> curr(sum + 1, false);
            curr[0] = true;
            for(int target = 1; target <= sum; target++){
                bool notTake = prev[target];
                bool take = false;
                if(arr[ind] <= target){
                    take = prev[target-arr[ind]];
                }
                curr[target] = take || notTake;
                
            }
            prev = curr;
        }
        return prev[sum];
    }
};
