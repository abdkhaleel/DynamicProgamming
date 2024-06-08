class Solution {
public:

    int minimumTotal(vector<vector<int>>& a) {
        int m = a.size();
        int n = a[m-1].size();
        vector<int> prev(n, 0);
        for(int i = m-1; i>=0; i--){
            vector<int> curr(i+1, 0);
            for(int j = i; j>=0; j--){
                if(i == m-1) curr[j] = a[i][j];
                else{
                    
                    // int c6 = a[i][j] + prev[j];
                    // int c4 = a[i][j] + prev[j+1];
                    curr[j] = min(a[i][j] + prev[j], a[i][j] + prev[j+1]);
                }
            }
            prev = curr;
        }
        return prev[0];
    }
};