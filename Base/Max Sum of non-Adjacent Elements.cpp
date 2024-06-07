class Solution {
public:
    int f(int ind, vector<int>& nums){

        if (ind == 0) return nums[ind];
        if (ind < 1) return 0;
        int pick, not_pick;
        pick = nums[ind] + f(ind - 2, nums);
        not_pick = 0 + f(ind - 1, nums);
        return max(pick, not_pick);

    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return f(n - 1, nums);
    }
};