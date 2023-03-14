class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 0;
        int dis = 0;
        while(i <= dis){
            dis = max(dis, i + nums[i]);
            if(dis >= nums.size() - 1)
                return true;
            i++;
        }
        return false;
    }
};