class Solution {
public:
    int fib[50];
    int climbStairs(int n) {
        fib[0]=fib[1]=1;
        for(int i=2;i<=n;i++){
            fib[i]=fib[i-1]+fib[i-2];
        }
        return fib[n];
    }
};