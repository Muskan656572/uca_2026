#include<stdio.h>
void reverse_string(char *str){
    int length = 0;
    while (str[length]!='\0' && str[length]!='\n') length++;
    int start = 0;
    int end = length-1;
    while(start < end){
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
    printf("String after reverse is: %s", str);
}
int main(){
    char str[1000];
    printf("Enter a string:");
    fgets(str, sizeof(str), stdin);
    reverse_string(str);
    return 0;
}