class Solution {
public:
   int helper(vector<int> arr, int i , int j){
    arr[i+1] = max(arr[i], arr[i+1]);
    for(int k = i+2; k <= j ; k++){
        arr[k] = max(arr[k] + arr[k-2], arr[k-1]);
    }
    return arr[j];
}
    int rob(vector<int>& nums) {
        int sz = nums.size();
        if(sz == 1)
            return nums[0];
        if(sz == 2)
            return max(nums[0],nums[1]);
        if(sz == 3)
            return max(nums[0], max(nums[1], nums[2]));
        return max(helper(nums,0,sz-2), helper(nums,1,sz-1));
        
    }
};