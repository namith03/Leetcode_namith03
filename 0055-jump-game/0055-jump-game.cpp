class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while(i < n){
            int jmp = nums[i];
            if(i == n-1)
                return true;
            if(jmp == 0)
                return false;
            if(i + jmp >= n - 1)
                return true;
            if(jmp == 1){
                i++;
                continue;
            }
            int j = 1;
            int maxm = 1;
            int k = j;
            while(j <= jmp){
                if(j + nums[i+j] > maxm)
                    k = j;
                maxm = max(min(n-1,maxm), j + nums[i+j]);
                j++;
            }
            i = i + k;
            cout << i << endl;
        }
        return false;
    }
};