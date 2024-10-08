#include "liststatik.h"
#include <stdio.h>

int main1(){
    ListStatik l;
    int i;
    CreateListStatik(&l);
    readList(&l);
    ELMT(l, getLastIdx(l)) += 1;
    if (ELMT(l, getLastIdx(l)) == 10){
        ELMT(l, getLastIdx(l)) = 0;
        for (i = getLastIdx(l) - 1; i  >= 0; i--){
            ELMT(l, i) = ELMT(l, i) + 1;
            if (ELMT(l, i) < 10){
                break;
            }else{
                if (i == 0){
                    ELMT(l, 0) = 0;
                    insertFirst(&l, 1);
                    
                }else{
                    ELMT(l, i) = 0;
                }
            }
        }
    }
    for (i = 0; i < listLength(l); i++){
        printf("%i", ELMT(l, i));
        if (i != getLastIdx(l)){
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}







