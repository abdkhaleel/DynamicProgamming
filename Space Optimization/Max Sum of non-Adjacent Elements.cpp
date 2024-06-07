class Solution {
public:
    int rob(vector<int>& nums) {
       
        int prev_1 = nums[0] , prev_2 = 0;
        int pick,n = nums.size();
        for(int i = 1; i < n; i++){
            pick = nums[i];
            if (i > 1) pick += prev_2;
            prev_2 = prev_1;
            (prev_1 < pick) ? (prev_1 = pick): 0;
        }
        return prev_1;
        
    }
};