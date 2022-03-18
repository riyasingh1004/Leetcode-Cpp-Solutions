// Time Complexity O(logn)

class Solution {
public:
    double myPow(double x, int n) {

        if (n == 0)
            return 1;
        
        double ans = 1, base = x;
        int N = abs(n);
        
        // braking the power into power of 2
        while (N > 0) {
            
            if (N & 1) 
                ans = (ans * base) ;
            base = (base * base);
            N = N >> 1;
            
        }

        return n < 0 ?  1/ans : ans;
        
    }
};