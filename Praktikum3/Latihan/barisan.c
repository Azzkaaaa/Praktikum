#include "listdin.h"
#include <stdio.h>

int main(){
    ListDin result;
    int i, j;
    int X, Y;
    int ctr = 0;
    
    CreateListDin(&result, 1000);
    readList(&result);
    
    // Insertion Sort
    for (i = 1; i < listLength(result); i++) {
        X = ELMT(result, i);  // Simpan elemen di posisi i ke variabel X
        j = i - 1;
        
        // Geser elemen-elemen yang lebih besar dari X ke kanan
        while (j >= 0 && ELMT(result, j) > X) {
            ctr++;
            ELMT(result, j + 1) = ELMT(result, j);  // Geser elemen ke kanan
            j--;
        }
        ELMT(result, j + 1) = X;  // Tempatkan X di posisi yang benar
    }

    printList(result);
    printf("\n");
    printf("%d\n", ctr);  // Menampilkan jumlah pertukaran
    return 0;
}
