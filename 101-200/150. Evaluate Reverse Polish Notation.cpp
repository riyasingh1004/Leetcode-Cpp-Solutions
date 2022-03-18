// Time Complexity O(N)

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int> s;
    
        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/")
            {
                int a=s.top(); s.pop();
                int b=s.top(); s.pop();
                
                if(tokens[i]=="+") {int num=b+a; s.push(num);}
                if(tokens[i]=="-") {int num=b-a; s.push(num);}
                if(tokens[i]=="*")   {int num=b*a; s.push(num);}
                if(tokens[i]=="/")  {int num=b/a; s.push(num);}  
            }
            else
            {
                s.push(stoi(tokens[i]));
            }
        }
        return s.top();
    }
    
};