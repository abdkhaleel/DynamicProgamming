class Solution {
public:
    // int f(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
    //     if(i < 0 || j < 0 || j > matrix.size()-1) return 1e9;
    //     if(i == 0) return matrix[i][j];
    //     if(dp[i][j] != -1) return dp[i][j];
    //     int s1 = matrix[i][j] + f(i-1, j-1, matrix, dp);
    //     int s2 = matrix[i][j] + f(i-1, j, matrix, dp);
    //     int s3 = matrix[i][j] + f(i-1, j+1, matrix, dp);
    //     return dp[i][j] = min(s1, min(s2, s3));
    // }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int minc = 1e9;
        
        for(int k = 0; k < n; k++){
            // vector<vector<int>> dp(n, vector<int>(n, 0));
            // dp[0] = matrix[0];
            vector<int> prev(n, 0);
            prev = matrix[0];
            for(int i = 1; i < n; i++){
                vector<int> curr(n, 0);
                for(int j = 0; j < n; j++){
                    int s1 = 1e9;
                    if(j > 0) s1 = matrix[i][j] + prev[j-1];
                    int s2 = matrix[i][j] + prev[j];
                    int s3 = 1e9;
                    if(j < n-1) s3 = matrix[i][j] + prev[j+1];
                    curr[j] = min(s1, min(s2, s3));
                }
                prev = curr;
            }
            minc = min(minc, prev[k]);
        }
        return minc;
    }
};