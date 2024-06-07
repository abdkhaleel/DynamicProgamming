int climbStairs(int n) {
    int prev = 1, prev_2 = 1,curr;
    for(int i=2; i<=n; i++){
        curr = prev + prev_2;
        prev_2 = prev;
        prev = curr;
    }
    return prev;
}