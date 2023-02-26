class Solution {
public:
    int arr[46] = { [0 ... 45] =-1};
    int climbStairs(int n) {
        if(n == 1)
            return 1;
        if(n == 2)
            return 2;
        if(arr[n] != -1)
            return arr[n];
        return arr[n] = climbStairs(n-1) + climbStairs(n-2);
    }
    
};