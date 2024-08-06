class Solution{   
public:
    bool f(int ind, int sum, vector<int>& arr){
        if(sum == 0) return true;
        if(ind == 0) return arr[ind] == sum;
        bool notTake = f(ind-1, sum, arr);
        bool take = false;
        if(arr[ind] <= sum) take = f(ind-1, sum-arr[ind], arr);
        return take || notTake;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        return f(arr.size()-1, sum, arr);
    }
};
