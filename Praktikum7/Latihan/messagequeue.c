#include <stdio.h>
#include "queue.h"

int main1() {
    int n;
    ElType val;
    int x;
    Queue l;
    CreateQueue(&l);
    scanf("%d", &n);

    // Lakukan inisialisasi Queue disini
    for (int i = 0; i < n; ++i) {
        int op;
        scanf("%d", &op);

        // Kerjakan keempat tipe query disini
        if (op == 1) {
            scanf("%d", &val);
            if (isFull(l)){
                printf("Queue Penuh\n");
            }else {
                enqueue(&l, val);
                printf("Enqueue %d Berhasil\n", val);
            }
        } else if (op == 2) {
            if (isEmpty(l)){
                printf("Queue Kosong\n");
            }else {
                dequeue(&l, &val);
                printf("Dequeue %d Berhasil\n", val);
            }
        } else if (op == 3) {
            if (isEmpty(l)){
                printf("Queue Kosong\n");
            }else {
                printf("Elemen Awal Queue adalah %d\n", HEAD(l));
            }
        } else if (op == 4) {
            printf("Ukuran Queue saat ini adalah %d\n", length(l));
        }
    }

    // Display Queue disini
    displayQueue(l);
    return 0;
}