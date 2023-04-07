class Solution {
public:
    string fractionToDecimal(int n, int d) {
        string result = "";
        if((n < 0 && d > 0) || (n>0 && d < 0)){
            result = '-' + result;
        }
        n = abs(n);
        d = abs(d);
        long int quo = n / d;
        long int rem = n % d;
        result = result + to_string(quo);
        if(rem == 0)
            return result;
        result = result + ".";
        unordered_map<int,int>map;
        while(rem != 0 && map.find(rem) == map.end()){
            map[rem] = result.length();
            rem = rem * 10;
            quo = rem / d;
            result = result + to_string(quo);
            rem = rem % d;
        }
        if(rem != 0){
            result = result.substr(0,map[rem]) + '('+result.substr(map[rem],result.length() - map[rem]) + ')';
        } 
        return result;
        }
};