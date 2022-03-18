// Time Complexity O(n)
class Solution {
public:
    bool check(char a, char b) {
        
        if (a == ')' && b == '(')
            return true;
        else if (a == '}' && b == '{')
            return true;
        else if (a == ']' && b == '[')
            return true;
        
        return false;
    }
    
    bool isValid(string s) {
        
        stack<char> st;
        
        for (int i = 0; i < s.length(); i++) {
            
            if(s[i] == '(' || s[i] == '{' || s[i] == '[' )
                st.push(s[i]);
            else if (s[i] == '}' || s[i] == ']' || s[i] == ')') {
                
                if (st.empty() || !check(s[i], st.top()))
                        return false;
                else 
                    st.pop();
                }
            }
        
        return st.empty();
        
    }
};