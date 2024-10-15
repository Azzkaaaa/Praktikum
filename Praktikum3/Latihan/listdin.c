#include "listdin.h"
#include <stdio.h>
#include <stdlib.h>


void CreateListDin(ListDin *l, int capacity){
    CAPACITY(*l) = capacity;
    NEFF(*l) = 0;
    BUFFER(*l) = (ElType *) malloc(capacity * sizeof(ElType));
}

void dealocateList(ListDin *l){
    free(BUFFER(*l));
    NEFF(*l) = 0;
    CAPACITY(*l) = 0;
}

int listLength(ListDin l){
    return NEFF(l);
}

IdxType getFirstIdx(ListDin l){
    return 0;
}

IdxType getLastIdx(ListDin l){
    return NEFF(l) - 1;
}

boolean isIdxValid(ListDin l, IdxType i){
    return (0 <= i && i < CAPACITY(l));
}

boolean isIdxEff(ListDin l, IdxType i){
    return (0 <= i && i < NEFF(l));
}

boolean isEmpty(ListDin l){
    return (NEFF(l) == 0);
}

boolean isFull(ListDin l){
    return (NEFF(l) == CAPACITY(l));
}

void readList(ListDin *l){
    int n;
    int i;
    do {
        scanf("%d", &n);
    }while(n < 0 || n > CAPACITY(*l));
    NEFF(*l) = n;
    for (i = 0; i < n; i++){
        scanf("%d", &ELMT(*l, i));
    }
}

void printList(ListDin l){
    int i;
    printf("[");
    for (i = 0; i < NEFF(l); i++){
        printf("%d", ELMT(l, i));
        if (i < NEFF(l) - 1){
            printf(",");
        }
    }
    printf("]");
}

ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus){
    int i;
    ListDin l3;
    CreateListDin(&l3, NEFF(l1));
    for(i = 0; i< NEFF(l1); i++){
        if (plus){
            ELMT(l3, i) = ELMT(l1, i) + ELMT(l2, i); 
        }else{
            ELMT(l3, i) = ELMT(l1, i) - ELMT(l2, i);
        }
    }
    NEFF(l3) = NEFF(l1);
    return l3;
}

boolean isListEqual(ListDin l1, ListDin l2){
    int i;
    if (listLength(l1) != listLength(l2)) return false;
    for(i = 0; i < NEFF(l1); i++){
        if (ELMT(l1, i) != ELMT(l2, i)){
            return false;
        } 
    }
    return true;
}

IdxType indexOf(ListDin l, ElType val){
    int i;
    
    if (isEmpty(l)){
        return IDX_UNDEF;
    }else{
        for (i = 0; i < NEFF(l); i++){
            if (ELMT(l, i) == val){
                return i;
            }
        }
    }
    return IDX_UNDEF;
}

void extremeValues(ListDin l, ElType *max, ElType *min){
    int i;

    *max = ELMT(l, 0);
    *min = ELMT(l, 0);
    for (i = 1; i < NEFF(l); i++){
        if (ELMT(l, i) > *max){
            *max = ELMT(l, i);
        }
        if (ELMT(l, i) < *min){
            *min = ELMT(l, i);
        }
    }
}

void copyList(ListDin lIn, ListDin *lOut){
    int i;

    CreateListDin(lOut, CAPACITY(lIn));
    NEFF(*lOut) = NEFF(lIn);
    for (i = 0; i < NEFF(*lOut); i++){
        ELMT(*lOut, i) = ELMT(lIn, i);
    }  
}

ElType sumList(ListDin l){
    int i;

    ElType sum;
    sum = 0;
    for (i = 0; i < NEFF(l); i++){
        sum += ELMT(l, i);
    }
    return sum;
}

int countVal(ListDin l, ElType val){
    int i;
    int ctr;

    ctr = 0;
    if (isEmpty(l)){
        return 0;
    }else{
        for (i = 0; i < NEFF(l); i++){
            if (val == ELMT(l, i)){
                ctr += 1;
            }
        }
    }
    return ctr;
}

void sort(ListDin *l, boolean asc){
    int i;
    int j;
    for (i = 0; i < NEFF(*l); i++){
        for (j = i + 1; j < NEFF(*l); j++){
            if ((asc && ELMT(*l, i) > ELMT(*l, j)) || (!asc && ELMT(*l, i) < ELMT(*l, j))) {
                ElType temp = ELMT(*l, i);
                ELMT(*l, i) = ELMT(*l, j);
                ELMT(*l, j) = temp;
            }
        }
    }
}

void insertLast(ListDin *l, ElType val){
    ELMT(*l, NEFF(*l)) = val;
    NEFF(*l)++;
}

void deleteLast(ListDin *l, ElType *val){
    *val = ELMT(*l, NEFF(*l) - 1);
    NEFF(*l)--;
}

void expandList(ListDin *l, int num){
    int newCap = CAPACITY(*l) + num;
    BUFFER(*l) = (ElType *) realloc(BUFFER(*l), newCap * sizeof(ElType));
    if (BUFFER(*l) != NULL) {
        CAPACITY(*l) = newCap;  
    }
}

void shrinkList(ListDin *l, int num){
    int newCap = CAPACITY(*l) - num;
    BUFFER(*l) = (ElType *) realloc(BUFFER(*l), newCap * sizeof(ElType));
    if (BUFFER(*l) != NULL) {
            CAPACITY(*l) = newCap;  
    }
}

void compressList(ListDin *l){
    BUFFER(*l) = (ElType*) realloc(BUFFER(*l), NEFF(*l) * sizeof(ElType));  // Realokasi memori sesuai jumlah elemen efektif
    if (BUFFER(*l) != NULL) {
        CAPACITY(*l) = NEFF(*l);  // Set kapasitas baru sama dengan jumlah elemen efektif
    }
}