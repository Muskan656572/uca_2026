#include<stdio.h>
int isPower2(int x){
    return !!x & !(x >> 31) & !(x & (x + (~0)));
}
int main(){
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    int answer = isPower2(number);
    printf("%d\n",answer);
    return 0;
}