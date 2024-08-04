class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int minc = 1e9;
        
        for(int k = 0; k < n; k++){
            vector<vector<int>> dp(n, vector<int>(n, 0));
            dp[0] = matrix[0];
            for(int i = 1; i < n; i++){
                for(int j = 0; j < n; j++){
                    int s1 = 1e9;
                    if(j > 0) s1 = matrix[i][j] + dp[i-1][j-1];
                    int s2 = matrix[i][j] + dp[i-1][j];
                    int s3 = 1e9;
                    if(j < n-1) s3 = matrix[i][j] + dp[i-1][j+1];
                    dp[i][j] = min(s1, min(s2, s3));
                }
            }
            minc = min(minc, dp[n-1][k]);
        }
        return minc;
    }
};