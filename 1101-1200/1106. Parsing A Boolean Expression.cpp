// Time Complexity O(N)

class Solution {
public:
    bool parseBoolExpr(string expression) {
        int i = 0;
        return parseExpr(expression, i);
    }
    
    bool parseExpr(string& e, int& i) {
        if(e[i] == 't') {
            i++;
            return true;
        } else if(e[i] == 'f') {
            i++;
            return false;
        } else if(e[i] == '!') {
            i++;
            i++;
            bool r = !parseExpr(e, i);
            i++;
            return r;
        } else if(e[i] == '&' || e[i] == '|') {
            bool isAnd = e[i] == '&';
            bool r = isAnd;
            i++;
            i++;
            while(e[i] != ')') {
                bool t = parseExpr(e, i);
                if(isAnd) r = r && t;
                else r = r || t;
                if(e[i] == ',') i++;
            }
            i++;
            return r;
        }
        return 0; // won't go here 
    }
};