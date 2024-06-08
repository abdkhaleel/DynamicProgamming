class Solution {
public:
    long f(int i, int j, vector<vector<int>>& a){
        if(i==a.size()-1) return a[i][j];
        if(i>=a.size() || j>i) return INT_MAX;

        long c6 = a[i][j]+f(i+1, j, a);
        long c4 = a[i][j]+f(i+1, j+1, a);
        return min(c6, c4);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        
        return f(0, 0, triangle);
    }
};