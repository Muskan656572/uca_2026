#include<stdio.h>
int my_strlen(const char *str) {
    int count = 0;
    while (str[count] != '\0' && str[count] != '\n') {
        count++;
    }
    return count;
}
int find_substring(const char *haystack, const char *needle){
    int haystack_len = my_strlen(haystack);
    int needle_len = my_strlen(needle);
    if (needle_len == 0){
        return 0;
    }

    if (needle_len > haystack_len) {
        return -1;
    }
    int i = 0;
    while (haystack[i] != '\0') {

        int j = 0;

        while (needle[j] != '\0' &&
               haystack[i + j] == needle[j]) {
            j++;
        }

        if (needle[j] == '\0')
            return i;

        i++;
    }

    return -1;
    
}
int main(){
    char haystack[1000];
    char needle[1000];

    printf("Enter haystack string: ");
    fgets(haystack, sizeof(haystack), stdin);
    haystack[my_strlen(haystack)] = '\0';

    printf("Enter needle string: ");
    fgets(needle, sizeof(needle), stdin);
    needle[my_strlen(needle)] = '\0';
    
    int result = find_substring(haystack, needle);
    printf("Result: %d\n", result);

    return 0;
}