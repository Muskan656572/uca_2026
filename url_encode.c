#include<stdio.h>
void url_encode(char *str, int true_length){

    int space_count = 0;
    for (int i = 0; i < true_length; i++) {
        if (str[i] == ' ') {
            space_count = space_count + 1;
        }
    }

    int new_length = true_length + (space_count * 2);
    str[new_length] = '\0';

    int old_pos = true_length - 1;   
    int new_pos = new_length - 1;
    while (old_pos >= 0) {

        if (str[old_pos] == ' ') {
    
            str[new_pos] = '0';
            str[new_pos - 1] = '2';
            str[new_pos - 2] = '%';
            new_pos = new_pos - 3;   
        }
        else {
            
            str[new_pos] = str[old_pos];
            new_pos = new_pos - 1;   
        }

        old_pos = old_pos - 1;   
    }
}

int main(){
    char str[1000];
    printf("Enter string: ");
    fgets(str, sizeof(str), stdin);
    int true_length;
    printf("Enter true_length: ");
    scanf("%d", &true_length);
    url_encode(str,true_length);
    printf("%s\n", str);
    return 0;
}