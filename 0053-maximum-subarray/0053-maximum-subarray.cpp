class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maximum = nums[0];
        int running_max = nums[0];
        for(int i = 1 ; i < nums.size(); i++){
            int dummy = max(nums[i],running_max + nums[i]);
            if(dummy >= maximum){
                maximum = dummy;
                running_max = dummy;
            }
            else
                running_max = max(nums[i],running_max + nums[i]);
        }
        return maximum;
    }
};