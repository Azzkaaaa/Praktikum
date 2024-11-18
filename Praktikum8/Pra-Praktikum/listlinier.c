#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

Address newNode(ElType val) {
    Address p = (Address) malloc(sizeof(Node));
    if (p != NULL) {
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}

void CreateList(List *l) {
    *l = NULL;
}

boolean isEmpty(List l) {
    return l == NULL;
}

ElType getElmt(List l, int idx) {
    int count = 0;
    Address p = l;
    while (p != NULL && count < idx) {
        p = NEXT(p);
        count++;
    }
    return INFO(p);
}

void setElmt(List *l, int idx, ElType val) {
    int count = 0;
    Address p = *l;
    while (p != NULL && count < idx) {
        p = NEXT(p);
        count++;
    }
    if (p != NULL) {
        INFO(p) = val;
    }
}

int indexOf(List l, ElType val) {
    int idx = 0;
    Address p = l;
    while (p != NULL) {
        if (INFO(p) == val) {
            return idx;
        }
        p = NEXT(p);
        idx++;
    }
    return IDX_UNDEF;
}

void insertFirst(List *l, ElType val) {
    Address p = newNode(val);
    if (p != NULL) {
        NEXT(p) = *l;
        *l = p;
    }
}

void insertLast(List *l, ElType val) {
    Address p = newNode(val);
    if (p != NULL) {
        if (isEmpty(*l)) {
            *l = p;
        } else {
            Address last = *l;
            while (NEXT(last) != NULL) {
                last = NEXT(last);
            }
            NEXT(last) = p;
        }
    }
}

void insertAt(List *l, ElType val, int idx) {
    if (idx == 0) {
        insertFirst(l, val);
    } else {
        Address p = newNode(val);
        if (p != NULL) {
            Address prev = *l;
            int count = 0;
            while (prev != NULL && count < idx - 1) {
                prev = NEXT(prev);
                count++;
            }
            if (prev != NULL) {
                NEXT(p) = NEXT(prev);
                NEXT(prev) = p;
            }
        }
    }
}

void deleteFirst(List *l, ElType *val) {
    if (!isEmpty(*l)) {
        Address p = *l;
        *val = INFO(p);
        *l = NEXT(p);
        free(p);
    }
}

void deleteLast(List *l, ElType *val) {
    if (!isEmpty(*l)) {
        Address prev = NULL;
        Address p = *l;
        while (NEXT(p) != NULL) {
            prev = p;
            p = NEXT(p);
        }
        *val = INFO(p);
        if (prev == NULL) {
            *l = NULL;
        } else {
            NEXT(prev) = NULL;
        }
        free(p);
    }
}

void deleteAt(List *l, int idx, ElType *val) {
    if (idx == 0) {
        deleteFirst(l, val);
    } else {
        Address prev = *l;
        int count = 0;
        while (prev != NULL && count < idx - 1) {
            prev = NEXT(prev);
            count++;
        }
        if (prev != NULL && NEXT(prev) != NULL) {
            Address p = NEXT(prev);
            *val = INFO(p);
            NEXT(prev) = NEXT(p);
            free(p);
        }
    }
}

void displayList(List l) {
    printf("[");
    Address p = l;
    while (p != NULL) {
        printf("%d", INFO(p));
        p = NEXT(p);
        if (p != NULL) {
            printf(",");
        }
    }
    printf("]");
}

int length(List l) {
    int count = 0;
    Address p = l;
    while (p != NULL) {
        count++;
        p = NEXT(p);
    }
    return count;
}

List concat(List l1, List l2) {
    List l3;
    CreateList(&l3);
    Address p = l1;
    while (p != NULL) {
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }
    p = l2;
    while (p != NULL) {
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }
    return l3;
}
