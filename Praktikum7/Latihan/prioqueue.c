#include "prioqueue.h"
#include <stdio.h>

void CreatePrioQueue(PrioQueue *pq) {
    IDX_HEAD(*pq) = IDX_UNDEF;
    IDX_TAIL(*pq) = IDX_UNDEF;
}

boolean isEmpty(PrioQueue pq) {
    return IDX_HEAD(pq) == IDX_UNDEF && IDX_TAIL(pq) == IDX_UNDEF;
}

boolean isFull(PrioQueue pq) {
    return (IDX_TAIL(pq) + 1) % CAPACITY == IDX_HEAD(pq);
}

int length(PrioQueue pq) {
    if (isEmpty(pq)) {
        return 0;
    }
    if (IDX_TAIL(pq) >= IDX_HEAD(pq)) {
        return IDX_TAIL(pq) - IDX_HEAD(pq) + 1;
    }
    return CAPACITY - (IDX_HEAD(pq) - IDX_TAIL(pq) - 1);
}

void enqueue(PrioQueue *pq, ElType val) {
    if (isEmpty(*pq)) {
        IDX_HEAD(*pq) = 0;
        IDX_TAIL(*pq) = 0;
        TAIL(*pq) = val;
    } else {
        IDX_TAIL(*pq) = (IDX_TAIL(*pq) + 1) % CAPACITY;
        TAIL(*pq) = val;

        int i = IDX_TAIL(*pq);
        while (i != IDX_HEAD(*pq) && (*pq).buffer[(i - 1 + CAPACITY) % CAPACITY] < val) {
            (*pq).buffer[i] = (*pq).buffer[(i - 1 + CAPACITY) % CAPACITY];
            i = (i - 1 + CAPACITY) % CAPACITY;
        }
        (*pq).buffer[i] = val;
    }
}

void dequeue(PrioQueue *pq, ElType *val) {
    if (isEmpty(*pq)) {
        printf("PrioQueue kosong, dequeue gagal.\n");
        return;
    }

    *val = HEAD(*pq);
    if (IDX_HEAD(*pq) == IDX_TAIL(*pq)) {
        IDX_HEAD(*pq) = IDX_UNDEF;
        IDX_TAIL(*pq) = IDX_UNDEF;
    } else {
        IDX_HEAD(*pq) = (IDX_HEAD(*pq) + 1) % CAPACITY;
    }
}

void displayPrioQueue(PrioQueue pq) {
    printf("[");
    if (!isEmpty(pq)) {
        int i = IDX_HEAD(pq);
        while (1) {
            printf("%d", pq.buffer[i]);
            if (i == IDX_TAIL(pq)) {
                break;
            }
            printf(",");
            i = (i + 1) % CAPACITY;
        }
    }
    printf("]\n");
}
