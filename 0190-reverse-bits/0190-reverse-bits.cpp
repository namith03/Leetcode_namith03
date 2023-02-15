class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int i = 0;
        while(i < 16){
            int j = 31 - i;
            int right = (n & (1<<i))>>i;
            int left = (n & (1<<j))>>j;
            if(left == right){
                i++;
                continue;
            }
            else{
                if(left == 1){
                    n = n | (1<<i); //making right 1
                    n = n & ~(1<<j); //making left = 0 when right is 0
                }
                else{
                    n = n & ~(1<<i); //making right 0 when left 0
                    n = n | (1<<j); //making left 1 when right 1
                }    
            } 
            i++;
        }
        return n;
    }
};