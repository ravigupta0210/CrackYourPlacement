// Reverse Integer


class Solution {
public:
    int reverse(int x) {
        long long r=0;
        while(x){
            int num = x%10;
            r = r*10+num;
            x /= 10;
        }
        if(r > INT_MAX || r< INT_MIN) return 0;
        else return int(r);
    }
};
