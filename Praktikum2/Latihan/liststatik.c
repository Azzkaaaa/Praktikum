#include <stdio.h>
#include "liststatik.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListStatik(ListStatik *l) {
    for (int i = 0; i < CAPACITY; i++) {
        ELMT(*l, i) = MARK;
    }
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListStatik l) {
    int count = 0;
    while (count < CAPACITY && ELMT(l, count) != MARK) {
        count++;
    }
    return count;
}

/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListStatik l) {
    return (isEmpty(l)) ? IDX_UNDEF : IDX_MIN;
}

IdxType getLastIdx(ListStatik l) {
    return listLength(l) - 1;
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListStatik l, IdxType i) {
    return (i >= 0 && i < CAPACITY);
}

boolean isIdxEff(ListStatik l, IdxType i) {
    return (i >= 0 && i < listLength(l));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty(ListStatik l) {
    return (ELMT(l, 0) == MARK);
}

/* *** Test List penuh *** */
boolean isFull(ListStatik l) {
    return (listLength(l) == CAPACITY);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readList(ListStatik *l) {
    int n;
    do {
        scanf("%d", &n);
    } while (n < 0 || n > CAPACITY);

    CreateListStatik(l);
    for (int i = 0; i < n; i++) {
        scanf("%d", &ELMT(*l, i));
    }
}

/* Proses : Menuliskan isi List dengan traversal */
void printList(ListStatik l) {
    printf("[");
    if (!isEmpty(l)) {
        for (int i = 0; i < listLength(l); i++) {
            if (i > 0) printf(",");
            printf("%d", ELMT(l, i));
        }
    }
    printf("]");
}

/* ********** OPERATOR ARITMATIKA ********** */
ListStatik plusMinusList(ListStatik l1, ListStatik l2, boolean plus) {
    ListStatik result;
    CreateListStatik(&result);
    int len = listLength(l1);

    for (int i = 0; i < len; i++) {
        if (plus) {
            ELMT(result, i) = ELMT(l1, i) + ELMT(l2, i);
        } else {
            ELMT(result, i) = ELMT(l1, i) - ELMT(l2, i);
        }
    }
    return result;
}

/* ********** OPERATOR RELASIONAL ********** */
boolean isListEqual(ListStatik l1, ListStatik l2) {
    if (listLength(l1) != listLength(l2)) {
        return false;
    }
    for (int i = 0; i < listLength(l1); i++) {
        if (ELMT(l1, i) != ELMT(l2, i)) {
            return false;
        }
    }
    return true;
}

/* ********** SEARCHING ********** */
int indexOf(ListStatik l, ElType val) {
    for (int i = 0; i < listLength(l); i++) {
        if (ELMT(l, i) == val) {
            return i;
        }
    }
    return IDX_UNDEF;
}

/* ********** NILAI EKSTREM ********** */
void extremeValues(ListStatik l, ElType *max, ElType *min) {
    *max = ELMT(l, 0);
    *min = ELMT(l, 0);
    for (int i = 1; i < listLength(l); i++) {
        if (ELMT(l, i) > *max) {
            *max = ELMT(l, i);
        }
        if (ELMT(l, i) < *min) {
            *min = ELMT(l, i);
        }
    }
}

/* ********** MENAMBAH ELEMEN ********** */
void insertFirst(ListStatik *l, ElType val) {
    if (!isFull(*l)) {
        for (int i = listLength(*l); i > 0; i--) {
            ELMT(*l, i) = ELMT(*l, i - 1);
        }
        ELMT(*l, 0) = val;
    }
}

void insertAt(ListStatik *l, ElType val, IdxType idx) {
    if (!isFull(*l) && isIdxEff(*l, idx)) {
        for (int i = listLength(*l); i > idx; i--) {
            ELMT(*l, i) = ELMT(*l, i - 1);
        }
        ELMT(*l, idx) = val;
    }
}

void insertLast(ListStatik *l, ElType val) {
    if (!isFull(*l)) {
        ELMT(*l, listLength(*l)) = val;
    }
}

/* ********** MENGHAPUS ELEMEN ********** */
void deleteFirst(ListStatik *l, ElType *val) {
    if (!isEmpty(*l)) {
        *val = ELMT(*l, 0);
        for (int i = 0; i < listLength(*l) - 1; i++) {
            ELMT(*l, i) = ELMT(*l, i + 1);
        }
        ELMT(*l, listLength(*l) - 1) = MARK;
    }
}

void deleteAt(ListStatik *l, ElType *val, IdxType idx) {
    if (!isEmpty(*l) && isIdxEff(*l, idx)) {
        *val = ELMT(*l, idx);
        for (int i = idx; i < listLength(*l) - 1; i++) {
            ELMT(*l, i) = ELMT(*l, i + 1);
        }
        ELMT(*l, listLength(*l) - 1) = MARK;
    }
}

void deleteLast(ListStatik *l, ElType *val) {
    if (!isEmpty(*l)) {
        *val = ELMT(*l, listLength(*l) - 1);
        ELMT(*l, listLength(*l) - 1) = MARK;
    }
}

/* ********** SORTING ********** */
void sortList(ListStatik *l, boolean asc) {
    int len = listLength(*l);
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            boolean condition = asc ? (ELMT(*l, j) > ELMT(*l, j + 1)) : (ELMT(*l, j) < ELMT(*l, j + 1));
            if (condition) {
                ElType temp = ELMT(*l, j);
                ELMT(*l, j) = ELMT(*l, j + 1);
                ELMT(*l, j + 1) = temp;
            }
        }
    }
}
