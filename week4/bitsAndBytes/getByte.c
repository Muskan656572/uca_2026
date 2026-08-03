#include<stdio.h>
int getByte(int x, int n){
    int shifts = n<<3;
    return (x>>shifts) & 0xFF;
}
int main(){
    int x, n;
    printf("Enter a number and byte you want to extract:");
    scanf("%x %d", &x, &n);
    int ans = getByte(x,n);
    printf("Byte %d of 0x%08X is: 0x%02X\n", n, x, ans);
    return 0;
}