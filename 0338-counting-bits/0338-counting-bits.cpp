class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n+1,0);
        result[0] = 0;
        if(n == 0)
            return result;
        result[1] = 1;
        if(n == 1)
            return result;
        result[2] = 1;
        if(n == 2)
            return result;
        int base = 2;
        int i = 3;
        while(i <= n){
            if((i & (i-1)) == 0){
                result[i] = 1;
                base = i;
            }
            else{
                result[i] = 1 + result[i-base];
            } 
            i++;            
        }
        return result;
    }
};