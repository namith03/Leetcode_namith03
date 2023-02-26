class Solution {
public:
    int helper(vector<int>&arr, int n){
        if(n == 1)
            return 1;
        if(n == 2)
            return 2;
        if(arr[n] != -1)
            return arr[n];
        else
            return arr[n] = helper(arr,n-1) + helper(arr,n-2);
    }
    int climbStairs(int n) {
        if(n == 1)
            return 1;
        vector<int> arr(n+1,-1);
        arr[1] = 1;
        arr[2] = 2;
        return helper(arr,n);
    }
    
};