// Happy Number


class Solution {
public:
int solve(int n){
    int newn=0;
    while(n!=0){
        int num=n%10;
        newn+= num*num;
        n/=10;
    }
    return newn;
}
    bool isHappy(int n) {
        unordered_set<int> set;
        while(n!=1 && !set.count(n)){
            set.insert(n);
            n = solve(n);
        }
        return n==1;
    }
};
