class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while(i < n){
            if(i == n-1 || i + nums[i] >= n - 1)
                return true;
            if(nums[i] == 0)
                return false;
            if(nums[i] == 1){
                i++;
                continue;
            }
            int j = 1;
            int maxm = 1;
            int k = j;
            while(j <= nums[i]){
                if(j + nums[i+j] > maxm)
                    k = j;
                maxm = max(min(n-1,maxm), j + nums[i+j]);
                j++;
            }
            i = i + k;
        }
        return false;
    }
};