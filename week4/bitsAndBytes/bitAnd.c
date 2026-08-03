#include<stdio.h>
int bitAnd(int x, int y){
    return ~(~x | ~y);
}
int main(){
    int x,y;
    printf("Enter value of x:");
    scanf("%d",&x);
    printf("Enter value of y:");
    scanf("%d",&y);
    int ans = bitAnd(x,y);
    printf("And of %d and %d is: %d\n",x,y,ans);
    return 0;
}