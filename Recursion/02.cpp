// Fibonacci Number


class Solution {
public:
int solve(int n){
    if(n==0 || n==1){
        return n;
    }
    return solve(n-1)+solve(n-2);
}
    int fib(int n) {
        return solve(n);
    }
};
