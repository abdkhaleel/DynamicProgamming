class Solution {
public:
    int f(int i, int j, vector<vector<int>>& a, vector<vector<int>>& dp){
        if(i==a.size()-1) return a[i][j];
        if(j>i) return INT_MAX;
        if(dp[i][j] != -1) return dp[i][j];
        long c6 = a[i][j]+f(i+1, j, a, dp);
        long c4 = a[i][j]+f(i+1, j+1, a, dp);
        return dp[i][j] = min(c6, c4);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(0, 0, triangle, dp);
    }
};