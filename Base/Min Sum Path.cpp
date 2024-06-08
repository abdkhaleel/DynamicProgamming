class Solution {
public:

    long f(int i, int j, vector<vector<int>>& grid){
        if(i == 0 && j == 0) return grid[0][0];
        if(i < 0 || j < 0) return INT_MAX;

        long up = grid[i][j] + f(i-1, j, grid);
        long left = grid[i][j] + f(i, j-1, grid);

        return min(up, left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        return f(m-1, n-1, grid);
    }
};