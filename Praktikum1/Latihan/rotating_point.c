#include "rotating_point.h"

#include <stdio.h>

#include "complex.h"
#include "point.h"

COMPLEX PowerCOMPLEX(COMPLEX C, int p) {
    COMPLEX C2 = C;
    int i = 1;
    for (i; i < p; ++i) {
        C2 = MultiplyCOMPLEX(C2, C);
    }
    return C2;
}

void TransformPointByComplexPower(POINT *P, COMPLEX C, int n) {
    int i = 0;
    COMPLEX pC;
    while (Jarak0(*P) <= 1.0 && i < n) {
        i++;
        pC = PowerCOMPLEX(C, i);
        float X = Absis(*P);
        float Y = Ordinat(*P);

        Absis(*P) = X * Real(pC) - Y * Imag(pC);
        Ordinat(*P) = X * Imag(pC) + Y * Real(pC);
    }
    if (i < n) {
        printf("Titik keluar dari lingkaran pada iterasi ke %d", i);
    } else {
        printf("Titik tetap berada di dalam lingkaran setelah %d iterasi", n);
    }
    return;
}