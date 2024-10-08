#include "liststatik.h"
#include <stdio.h>

int main() {
    ListStatik l;
    int freq[101] = {0}; // Asumsi elemen list tidak lebih dari 100, sesuaikan jika perlu
    int max1 = 0, max2 = 0;
    int val1 = -1, val2 = -1; // Nilai elemen yang muncul paling sering dan kedua
    int i;

    CreateListStatik(&l);
    readList(&l);

    // Hitung frekuensi setiap elemen
    for (i = 0; i < listLength(l); i++) {
        freq[ELMT(l, i)]++;
    }

    // Cari frekuensi terbesar dan kedua terbesar
    for (i = 0; i < 101; i++) {
        if (freq[i] > max1) {
            // Update max2 dengan max1 sebelumnya
            max2 = max1;
            val2 = val1;

            // Update max1 dengan frekuensi baru
            max1 = freq[i];
            val1 = i;
        } else if (freq[i] > max2 && freq[i] < max1) {
            // Update max2 jika frekuensi lebih kecil dari max1 tapi lebih besar dari max2
            max2 = freq[i];
            val2 = i;
        }
    }

    // Output hasil
    if (max2 > 0) {
        printf("%d\n", val2);
    } else {
        printf("Tidak ada elemen kedua yang paling sering muncul\n");
    }

    return 0;
}
