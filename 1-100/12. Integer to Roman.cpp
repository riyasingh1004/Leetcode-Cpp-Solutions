// Time Cpmplexity O(n)

class Solution {
public:
    string intToRoman(int number) {
        
        string res = "";
        int num[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
        string sym[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        int i = 12;   
        while(number>0) {
          int div = number/num[i];
          number = number%num[i];
          while(div--)
            res += sym[i];
          i--;
        }
        return res;   
    }
};