#include<stdio.h>
int conditional(int x, int y, int z){
    int mask = !!x;
    mask = ~mask + 1;
    return (mask & y) | (~mask & z);
}
int main(){
    int x, y, z;
    printf("Enter three numbers:");
    scanf("%d %d %d", &x, &y, &z);
    int ans = conditional(x,y,z);
    printf("%d\n",ans);
    return 0;
}