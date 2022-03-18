// Time Complexity O(32)

class Solution {
public:
    uint32_t reverseBits(uint32_t A) {
        
        uint32_t B = 0;
        for (int i = 0; i < 32; i++) {
            
            // last digit
            int k = A & 1;
            // left shift the result
            B = B << 1;
            B = B | k;
            // right shift the number
            A = A >> 1;
        }
        return B;
    }
};