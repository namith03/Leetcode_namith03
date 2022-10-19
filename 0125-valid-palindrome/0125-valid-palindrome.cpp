class Solution {
public:
    bool isPalindrome(string s) {
        int j = 0;
        for(int i = 0; i < s.length(); i++){
            s[i]=tolower(s[i]);
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
                s[j] = s[i];
                j++;
            }
}
        s = s.substr(0,j);
        int left = 0; int right = s.length()-1;
        while(left < right){
            if(s[left] != s[right])
                return false;
            left++;
            right--;
        }
    return true;
    }
};