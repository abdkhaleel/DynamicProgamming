class Solution {
public:
    int f(int i, int j, vector<vector<int>>& matrix){
        if(i < 0 || j < 0 || j > matrix.size()-1) return 1e9;
        if(i == 0) return matrix[i][j];
        int s1 = matrix[i][j] + f(i-1, j-1, matrix);
        int s2 = matrix[i][j] + f(i-1, j, matrix);
        int s3 = matrix[i][j] + f(i-1, j+1, matrix);
        return min(s1, min(s2, s3));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int minc = 1e9;
        for(int i = 0; i < n; i++){
            minc = min(minc, f(n-1, i, matrix));
        }
        return minc;
    }
};