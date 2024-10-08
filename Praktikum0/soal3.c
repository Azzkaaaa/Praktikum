#include <stdio.h>
int main(){
    int a;
    int b;
    int n;
    int f;
    int f2;
    int temp;
    int count;
    int i;
    scanf("%d", &n);
    scanf("%d", &a);
    scanf("%d", &b);
    for (i = 0; i < n;i++){
        temp = a;
        a = b;
        b = temp + a;
    }
    printf("%d\n", b);
    return 0;
}