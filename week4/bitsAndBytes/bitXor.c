#include<stdio.h>
int bitXor(int x, int y){
    return ~ (x & y) & ~ (~x & ~y);
}
int main(){
    int x,y;
    printf("Enter value of x:");
    scanf("%d",&x);
    printf("Enter value of y:");
    scanf("%d",&y);
    int ans = bitXor(x,y);
    printf("Xor of %d and %d is: %d\n",x,y,ans);
    return 0;
}