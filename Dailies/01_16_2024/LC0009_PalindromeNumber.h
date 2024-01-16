// O(d) Time where d = digits in x
// O(1) Space
class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers are never palindromes: -221 ~~ 221-
        if(x < 0) return false;
        // Single digit numbers are palindromes.
        if(x < 10) return true;
        // Cannot have a palindrome number with unit in 0, that would mean having a number
        // such as 02320 which makes no sense.
        if(x%10 == 0) return false;

        // Storage for reversing x and a tmp var for the current state of the other half of x
        // that is not reversed.
        long reverseNum = 0;
        long xTmp = x;
        while(xTmp > 0){
            // Create space for unit digit and add it.
            reverseNum *= 10;
            reverseNum += (xTmp % 10);
            // Remove unit digit
            xTmp /= 10;
            //Check if our reverse number is equal to current state of number or if our reverse number
            // equals current state of our number without unit place for odd-digit numbers.
            if(reverseNum == xTmp || (reverseNum == xTmp / 10 && xTmp != 0 && reverseNum != 0)) 
                return true;
        }
        return false;
        
    }
};