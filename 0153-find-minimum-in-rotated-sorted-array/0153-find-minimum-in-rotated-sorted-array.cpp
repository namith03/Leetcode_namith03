class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        while(l < r){
            if(nums[(l+r)/2] > nums[r])
                l = ((l+r)/2)+1;
            else
                r = (l+r)/2;
        }
        return nums[l];
    }
};