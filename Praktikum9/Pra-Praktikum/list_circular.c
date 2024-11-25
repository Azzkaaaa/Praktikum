#include <stdio.h>
#include <stdlib.h>
#include "list_circular.h"

boolean isEmpty(List l) {
    return FIRST(l) == NULL;
}

void CreateList(List *l) {
    FIRST(*l) = NULL;
}

Address allocate(ElType val) {
    Address newNode = (Address)malloc(sizeof(ElmtList));
    if (newNode != NULL) {
        INFO(newNode) = val;
        NEXT(newNode) = NULL;
    }
    return newNode;
}

void deallocate(Address P) {
    free(P);
}

Address search(List l, ElType val) {
    if (isEmpty(l)) return NULL;

    Address current = FIRST(l);
    do {
        if (INFO(current) == val) return current;
        current = NEXT(current);
    } while (current != FIRST(l));
    return NULL;
}

boolean addrSearch(List l, Address p) {
    if (isEmpty(l)) return false;

    Address current = FIRST(l);
    do {
        if (current == p) return true;
        current = NEXT(current);
    } while (current != FIRST(l));
    return false;
}

void insertFirst(List *l, ElType val) {
    Address newNode = allocate(val);
    if (newNode != NULL) {
        if (isEmpty(*l)) {
            FIRST(*l) = newNode;
            NEXT(newNode) = newNode;  
        } else {
            Address last = FIRST(*l);
            while (NEXT(last) != FIRST(*l)) {
                last = NEXT(last);
            }
            NEXT(newNode) = FIRST(*l);
            FIRST(*l) = newNode;
            NEXT(last) = newNode;
        }
    }
}

void insertLast(List *l, ElType val) {
    Address newNode = allocate(val);
    if (newNode != NULL) {
        if (isEmpty(*l)) {
            FIRST(*l) = newNode;
            NEXT(newNode) = newNode; 
        } else {
            Address last = FIRST(*l);
            while (NEXT(last) != FIRST(*l)) {
                last = NEXT(last);
            }
            NEXT(last) = newNode;
            NEXT(newNode) = FIRST(*l);
        }
    }
}

void deleteFirst(List *l, ElType *val) {
    if (!isEmpty(*l)) {
        Address temp = FIRST(*l);
        *val = INFO(temp);
        if (NEXT(temp) == FIRST(*l)) {  
            FIRST(*l) = NULL;
        } else {
            Address last = FIRST(*l);
            while (NEXT(last) != FIRST(*l)) {
                last = NEXT(last);
            }
            FIRST(*l) = NEXT(temp);
            NEXT(last) = FIRST(*l);
        }
        deallocate(temp);
    }
}

void deleteLast(List *l, ElType *val) {
    if (!isEmpty(*l)) {
        Address current = FIRST(*l), prev = NULL;
        while (NEXT(current) != FIRST(*l)) {
            prev = current;
            current = NEXT(current);
        }
        *val = INFO(current);
        if (prev == NULL) {  
            FIRST(*l) = NULL;
        } else {
            NEXT(prev) = FIRST(*l);
        }
        deallocate(current);
    }
}

void displayList(List l){
    printf("[");
    Address p = FIRST(l);
    while (NEXT(p)!=FIRST(l)){
        printf("%d,", INFO(p));
        p = NEXT(p);
    }
    if (p != NULL){
        printf("%d", INFO(p));
    }
    printf("]");
}
