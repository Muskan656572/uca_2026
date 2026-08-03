#include<stdio.h>
int sign(int number){
    return (number >> 31) | !!number;
}
int main(){
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    int ans = sign(number);
    printf("Sign of %d is: %d\n", number, ans);
    return 0;
}