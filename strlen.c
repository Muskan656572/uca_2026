#include <stdio.h>
int my_strlen(const char *str){
    int count = 0;
    while(*str!='\0' && *str!='\n'){
        count++;
        str++;
    }
    return count;
}
int main(){
    char str[1000];
    printf("Enter a string:");
    fgets(str, sizeof(str), stdin);
    int length = my_strlen(str);
    printf("Length of string is: %d\n", length);
    return 0;
}