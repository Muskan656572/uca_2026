#include<stdio.h>
int logicalShift(int x, int n) {
    int mask = ~(((1 << 31) >> n) << 1);
    return (x >> n) & mask;
}
int main(){
    int x, n;
    printf("Enter a number and shift amount:");
    scanf("%x %d", &x, &n);
    int ans = logicalShift(x,n);
    printf("Logical shift of 0x%08X by %d is: 0x%08X\n", x, n, ans);
    return 0;
}