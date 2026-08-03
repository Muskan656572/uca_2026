#include<stdio.h>
int bang(int x){
    return ((x | (~x + 1)) >> 31) + 1;
}
int main(){
    int x;
    printf("Enter a number:");
    scanf("%d",&x);
    int ans = bang(x);
    printf("Bang of %d is: %d\n", x, ans);
    return 0;
}