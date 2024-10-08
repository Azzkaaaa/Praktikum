#include "liststatik.h"
#include <stdio.h>
#include "boolean.h"


int main2(){
    ListStatik l;
    ListStatik result;
    int i;
    int j;
    int ctr;
    int isDuplicate;
    isDuplicate = 0;
    ctr = 0;
    CreateListStatik(&l);
    CreateListStatik(&result);
    readList(&l);
    // Hapus duplikat
    ELMT(result, 0) = ELMT(l, 0);
    for (i = 0; i < listLength(l); i++){
        for (j = i - 1; j >= 0; j--){
            if (ELMT(l, i) == ELMT(l, j)){
                isDuplicate = 0;
                break;
            }else{
                isDuplicate = 1;

            }
        }
        if (isDuplicate == 1){
            insertLast(&result, ELMT(l,i));

        }
    }
    printList(result);
    printf("\n");
    // Cek duplikat
    for (i = 0; i < listLength(result); i++){
        for (j = i; j < listLength(l); j++){
            if (ELMT(result, i) == ELMT(l, j)){
                ctr = ctr + 1;
            }
        }
        printf("%d %d\n", ELMT(result, i), ctr);
        ctr = 0;
    }
    return 0;
}