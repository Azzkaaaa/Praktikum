#include "fraction.h"
#include "stdio.h"

int GCD(int a, int b) {
    if (b == 0)
        return a;
    else
        return GCD(b, a % b);
}

boolean IsFRACTIONValid(int N, int D){
    return D != 0;
}

void CreateFRACTION(FRACTION *F, int N, int R){
    Numerator(*F) = N;
    Denominator(*F) = R;
}

void ReadFRACTION(FRACTION *F){
    int N, D;
    do{
        scanf("%d %d", &N, &D);
        if (!IsFRACTIONValid(N, D)){
            printf("FRACTION tidak valid\n");
        }
    }while(!IsFRACTIONValid(N, D));
    CreateFRACTION(F, N, D);
}

void WriteFRACTION(FRACTION F){
    FRACTION simplified = SimplifyFRACTION(F);
    printf("%d/%d", simplified.N, simplified.D);
}

/* *** Operasi penjumlahan FRACTION *** */
FRACTION AddFRACTION(FRACTION F1, FRACTION F2) {
    FRACTION result;
    result.N = (F1.N * F2.D) + (F2.N * F1.D);
    result.D = F1.D * F2.D;
    return SimplifyFRACTION(result);
}

/* *** Operasi pengurangan FRACTION *** */
FRACTION SubtractFRACTION(FRACTION F1, FRACTION F2) {
    FRACTION result;
    result.N = (F1.N * F2.D) - (F2.N * F1.D);
    result.D = F1.D * F2.D;
    return SimplifyFRACTION(result);
}

/* *** Operasi perkalian FRACTION *** */
FRACTION MultiplyFRACTION(FRACTION F1, FRACTION F2) {
    FRACTION result;
    result.N = F1.N * F2.N;
    result.D = F1.D * F2.D;
    return SimplifyFRACTION(result);
}

/* *** Operasi pembagian FRACTION *** */
FRACTION DivideFRACTION(FRACTION F1, FRACTION F2) {
    FRACTION result;
    result.N = F1.N * F2.D;
    result.D = F1.D * F2.N;
    return SimplifyFRACTION(result);
}

/* *** Perkalian FRACTION dengan bilangan bulat *** */
FRACTION MultiplyNumberFRACTION(int n, FRACTION F) {
    FRACTION result;
    result.N = F.N * n;
    result.D = F.D;
    return SimplifyFRACTION(result);
}

/* *** Penyederhanaan FRACTION *** */
FRACTION SimplifyFRACTION(FRACTION F) {
    int gcd = GCD(abs(F.N), abs(F.D));
    F.N /= gcd;
    F.D /= gcd;
    
    if (F.D < 0) {  // Pastikan penyebut positif
        F.N = -F.N;
        F.D = -F.D;
    }
    
    return F;
}

/* *** Konversi ke desimal *** */
float ToDecimal(FRACTION F) {
    return (float)F.N / (float)F.D;
}