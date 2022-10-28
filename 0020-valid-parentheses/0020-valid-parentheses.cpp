class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        if(s.length() % 2 != 0)
            return false;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ')'){
                if(stack.size() == 0 || stack.top() != '(')
                    return false;
                else
                    stack.pop();
            }
             else if(s[i] == ']'){
                if(stack.size() == 0 || stack.top() != '[')
                    return false;
                 else
                     stack.pop();
            }
             else if(s[i] == '}'){
                if(stack.size() == 0 || stack.top() != '{')
                    return false;
                 else
                     stack.pop();
            }
            else if (s[i] == '(' || s[i] == '[' || s[i] == '{'){
                stack.push(s[i]);
            }
        }
        if(stack.empty())
            return true;
        else
            return false;
    }
};