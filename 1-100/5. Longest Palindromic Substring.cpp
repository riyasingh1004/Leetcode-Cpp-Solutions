// Time Complexity O(n*n)

class Solution {
public:
    string longestPalindrome(string s) {
        

        int n = s.length();
        bool table[n][n];
        memset(table,0,sizeof(table));
        int maxlength = 1;
        int start = 0;
        string res = "";
        // all single characters are pallindrome
        for(int i=0;i<n;i++)
            table[i][i]=true;
        //checking for adjacent letters
        for(int i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])
            {
                table[i][i+1]=true;
                start=i;
                maxlength=2;
            }
        }
        // k is the length of substring
        // table[i+1][j-1] checks for characters between i...j for pallindrome
        for(int k=3;k<=n;k++)
        {
            for(int i=0;i<n-k+1;i++)
            {
                int j = i+k-1;
                if(s[i]==s[j] && table[i+1][j-1])
                {
                    table[i][j]=true;
                    if(k>maxlength)
                    {
                        start=i;
                        maxlength=k;
                    }
                    
                }
             }
        }
        
        for(int i=start;i<=(maxlength+start-1);i++)
            res+=s[i];
        
        return res;
        
    }
};