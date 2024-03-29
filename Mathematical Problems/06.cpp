//Palindrome Number


class Solution {
public:
    bool isPalindrome(int x) {
        long long temp = x;
        long long reverse = 0;
        if(x<0) return false;
        while(temp!=0){
            int num = temp%10;
            reverse = reverse * 10 + num;
            temp/= 10;
        }
        return reverse == x;
    }
};
