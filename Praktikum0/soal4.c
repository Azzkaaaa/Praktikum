#include <stdio.h>
int main() {
    int a;
    int b;
    int ganjil;
    scanf("%d", &a);
    scanf("%d", &b);
    while (a < b) {
        ganjil = a % 2;
        if (ganjil == 1) {
            a = a + 1;
        } else {
            a = a * 2;
        }
        
        // Cek apakah nilai a masih kurang dari b sebelum mencetak
        if (a < b) {
            printf("%d", a);
            if (a * 2 < b) { // Cek apakah akan ada angka berikutnya
                printf(" ");
            }
            
        }
    }
    printf("\n");
    return 0;
}
