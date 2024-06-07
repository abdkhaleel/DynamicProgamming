class Solution {
public:

    int f(int i, int j, vector<vector<int>>& grid){

        if(i < 0 || j < 0) return 0;
        if(grid[i][j] == 1) return 0;
        if(i == 0 && j == 0) return 1;

        int up = f(i-1, j, grid);
        int left = f(i, j-1, grid);

        return up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        return f(m-1, n-1, obstacleGrid);
    }
};