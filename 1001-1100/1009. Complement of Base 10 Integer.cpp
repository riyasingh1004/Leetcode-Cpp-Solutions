// Time Complexity O(log(n))

// Now we take modulo of 5 i.e.  % 2 ----> 1     ^
// 								2 ----> 0     |
// 								1 ----> 1     |
// 		and finally it become's 0 

// What I did is we take modulo of 5 i.e. 5 % 2 = 1 ;then divide by 2 i.e         5 / 2 = 2;
// again modulo of 2 i.e                  2 % 2 = 0 ;then again we divide by 2    2 / 2 = 1;


// going from down to top, we will get 101, now by compliment we can convert 101 to 010

// Now for 010, taking least significant digit. we go from right to left
// i.e. 0 * 2^0
//     +1 * 2^1
//     +0 * 2^2
//     ---------
//     =   2

class Solution {
public:
    int bitwiseComplement(int n) {
        
        if (n == 0)
            return 1;
        int ans = 0, f = 1; 
        while (n != 0) {
            
            ans += f*(n % 2 == 0 ? 1 : 0);
            f *= 2;
            n /= 2;
        }
        return ans;
    }
};