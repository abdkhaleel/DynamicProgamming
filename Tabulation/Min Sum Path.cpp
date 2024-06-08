class Solution {
public:

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> prev(n, 0);
        for(int i = 0; i < m; i++){
            vector<int> curr(n, 0);
            for(int j = 0; j < n; j++){
               if(i == 0 && j == 0) curr[0] = grid[0][0]; 
               else{
                long up = INT_MAX, left = INT_MAX;
                if(i > 0) up = grid[i][j] + prev[j];
                if(j > 0) left = grid[i][j] + curr[j-1];
                curr[j] = min(up, left);

               }
            }
            prev = curr;
        }
        return prev[n-1];
    }
};