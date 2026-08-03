#include<stdio.h>
int fitsBits(int x, int n) {
    int shift = 32 + (~n + 1);   // 32 - n
    return !(((x << shift) >> shift) ^ x);
}
int main(){
    int x, n;
    printf("Enter a number and number of bits:");
    scanf("%d %d", &x, &n);
    int ans = fitsBits(x,n);
    printf("Does %d fit in %d bits? %d\n", x, n, ans);  
    return 0;
}