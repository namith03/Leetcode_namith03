class Solution {
public:
    int getSum(int a, int b) {
        unsigned int carry;
        unsigned int b1 = b;
        while(b1!=0){
            carry = a&b1;
            a = a^b1;
            b1 = carry<<1;
        }
        return a;
    }
};