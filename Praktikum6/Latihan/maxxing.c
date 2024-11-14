#include <stdio.h>
#include "boolean.h"
#include "stack.h"

#define MXN 10007  // Menggunakan define agar bisa dipakai untuk ukuran array global

int N;
int heights[MXN];
int maxStrength[MXN];
int left[MXN], right[MXN];

int main() {
    // Baca input
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &heights[i]);
    }

    // Stack untuk menghitung batas kiri dan kanan dari setiap prajurit
    Stack s;
    CreateEmpty(&s);

    // Menghitung batas kiri untuk setiap prajurit
    for (int i = 0; i < N; i++) {
        while (!IsEmpty(s) && heights[InfoTop(s)] >= heights[i]) {
            Pop(&s, &left[i]);
        }
        left[i] = IsEmpty(s) ? -1 : InfoTop(s);
        Push(&s, i);
    }

    // Mengosongkan stack untuk perhitungan batas kanan
    CreateEmpty(&s);

    // Menghitung batas kanan untuk setiap prajurit
    for (int i = N - 1; i >= 0; i--) {
        while (!IsEmpty(s) && heights[InfoTop(s)] >= heights[i]) {
            Pop(&s, &right[i]);
        }
        right[i] = IsEmpty(s) ? N : InfoTop(s);
        Push(&s, i);
    }

    // Inisialisasi kekuatan maksimal setiap ukuran kelompok dengan nilai awal
    for (int i = 1; i <= N; i++) {
        maxStrength[i] = 0;
    }

    // Menghitung kekuatan maksimal setiap ukuran kelompok
    for (int i = 0; i < N; i++) {
        int len = right[i] - left[i] - 1;
        if (heights[i] > maxStrength[len]) {
            maxStrength[len] = heights[i];
        }
    }

    // Propagasi kekuatan maksimal dari ukuran terbesar ke ukuran terkecil
    for (int i = N - 1; i >= 1; i--) {
        if (maxStrength[i + 1] > maxStrength[i]) {
            maxStrength[i] = maxStrength[i + 1];
        }
    }

    // Output hasil
    for (int i = 1; i <= N; i++) {
        printf("%d ", maxStrength[i]);
    }
    printf("\n");

    return 0;
}
