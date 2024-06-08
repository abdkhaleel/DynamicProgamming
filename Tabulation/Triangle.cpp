class Solution {
public:

    int minimumTotal(vector<vector<int>>& a) {
        int m = a.size();
        int n = a[m-1].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = m-1; i>=0; i--){
            for(int j = i; j>=0; j--){
                if(i == m-1) dp[i][j] = a[i][j];
                else{
                    
                    int c6 = a[i][j] + dp[i+1][j];
                    int c4 = a[i][j] + dp[i+1][j+1];
                    dp[i][j] = min(c6, c4);
                }
            }
        }
        return dp[0][0];
    }
};