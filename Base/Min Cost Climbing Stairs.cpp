class Solution {
public:
    int f(vector<int>& cost, int i){
        if(i < 0) return 1e9;
        if(i == 1) return cost[1];
        if(i == 0) return cost[0];
        int single_step = cost[i] + f(cost, i-1);
        int double_step = cost[i] + f(cost, i-2);

        return min(single_step, double_step);

    }
    int minCostClimbingStairs(vector<int>& cost) {
        return min(f(cost, cost.size()-1), f(cost, cost.size()-2));        
    }
};