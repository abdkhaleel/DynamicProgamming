class Solution {
public:
    int f(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(i < 0 || j < 0 || j > matrix.size()-1) return 1e9;
        if(i == 0) return matrix[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        int s1 = matrix[i][j] + f(i-1, j-1, matrix, dp);
        int s2 = matrix[i][j] + f(i-1, j, matrix, dp);
        int s3 = matrix[i][j] + f(i-1, j+1, matrix, dp);
        return dp[i][j] = min(s1, min(s2, s3));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int minc = 1e9;
        
        for(int i = 0; i < n; i++){
            vector<vector<int>> dp(n, vector<int>(n, -1));
            minc = min(minc, f(n-1, i, matrix, dp));
        }
        return minc;
    }
};