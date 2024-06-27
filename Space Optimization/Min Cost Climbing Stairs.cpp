class Solution {
public:

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int prev0 = cost[0], prev = cost[1];
        for(int i = 2; i < n; i++){
            int single_step = cost[i] + prev;
            int double_step = cost[i] + prev0;
            int curr = min(single_step, double_step);
            prev0 = prev;
            prev = curr;
        }
        return min(prev, prev0);        
    }
};