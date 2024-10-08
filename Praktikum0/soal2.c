#include <stdio.h>
int main(){
    int n;
    int x;
    int i;
    int j;
    int count;
    scanf("%d", &n);
    x = (2 * n) - 1;
    count = n - 1;
    for (i = 0; i < n; i++){
        if (i > 0){
            for (j = count; j < n;j++){
                printf(" ");
            }count--;
        }
        for (j = i; j < x; j++){
            printf("*");
        
        
        
        }
        
        x--;
        printf("\n");
    }
    return 0;

}