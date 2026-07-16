#include<stdio.h>
long long bruteSum(long long n){
    if (n<2) return 0;
    long long sum = 0;
    long long a = 1, b = 1;
    while (b <= n) {
        if (b % 2 == 0)
            sum += b;

        long long c = a + b;
        a = b;
        b = c;
    }

    return sum;
}
long long OptimizedSum(long long n){
    if (n<2) return 0;
    long long sum = 0;
    long long a = 2, b = 8;
    while (a <= n) {
        sum += a;
        long long c = 4 * b + a;
        a = b; 
        b = c;
    }
    return sum;
}
int main(){
    long long n;
    printf("Enter a number:");
    scanf("%lld", &n);
    printf("Brute Force Sum is: %lld\n", bruteSum(n));
    printf("Optimized Approach Sum is: %lld\n", OptimizedSum(n));
   return 0;
}