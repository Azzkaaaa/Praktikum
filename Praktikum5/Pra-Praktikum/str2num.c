#include <stdio.h>
#include "boolean.h"
#include "mesinkarakter.h"
#include "mesinkata.h"

boolean isBelas() {
    return
    currentWord.Length == 5 &&
    currentWord.TabWord[0] == 'b' &&
    currentWord.TabWord[1] == 'e' &&
    currentWord.TabWord[2] == 'l' &&
    currentWord.TabWord[3] == 'a' &&
    currentWord.TabWord[4] == 's';
}
boolean isPuluh() {
    return 
    currentWord.Length == 5 &&
    currentWord.TabWord[0] == 'p' &&
    currentWord.TabWord[1] == 'u' &&
    currentWord.TabWord[2] == 'l' &&
    currentWord.TabWord[3] == 'u' &&
    currentWord.TabWord[4] == 'h';
}
boolean isRatus() {
    return 
    currentWord.Length == 5 &&
    currentWord.TabWord[0] == 'r' &&
    currentWord.TabWord[1] == 'a' &&
    currentWord.TabWord[2] == 't' &&
    currentWord.TabWord[3] == 'u' &&
    currentWord.TabWord[4] == 's';
}
boolean isAngka() {
    return
    currentWord.Length == 3 &&
    currentWord.TabWord[0] == 'n' &&
    currentWord.TabWord[1] == 'o' &&
    currentWord.TabWord[2] == 'l'
    ||
    currentWord.Length == 4 &&
    currentWord.TabWord[0] == 's' &&
    currentWord.TabWord[1] == 'a' &&
    currentWord.TabWord[2] == 't' &&
    currentWord.TabWord[3] == 'u'
    ||
    currentWord.Length == 3 &&
    currentWord.TabWord[0] == 'd' &&
    currentWord.TabWord[1] == 'u' &&
    currentWord.TabWord[2] == 'a'
    ||
    currentWord.Length == 4 &&
    currentWord.TabWord[0] == 't' &&
    currentWord.TabWord[1] == 'i' &&
    currentWord.TabWord[2] == 'g' &&
    currentWord.TabWord[3] == 'a'
    ||
    currentWord.Length == 5 &&
    currentWord.TabWord[0] == 'e' &&
    currentWord.TabWord[1] == 'm' &&
    currentWord.TabWord[2] == 'p' &&
    currentWord.TabWord[3] == 'a' &&
    currentWord.TabWord[4] == 't'
    ||
    currentWord.Length == 4 &&
    currentWord.TabWord[0] == 'l' &&
    currentWord.TabWord[1] == 'i' &&
    currentWord.TabWord[2] == 'm' &&
    currentWord.TabWord[3] == 'a'
    ||
    currentWord.Length == 4 &&
    currentWord.TabWord[0] == 'e' &&
    currentWord.TabWord[1] == 'n' &&
    currentWord.TabWord[2] == 'a' &&
    currentWord.TabWord[3] == 'm'
    ||
    currentWord.Length == 5 &&
    currentWord.TabWord[0] == 't' &&
    currentWord.TabWord[1] == 'u' &&
    currentWord.TabWord[2] == 'j' &&
    currentWord.TabWord[3] == 'u' &&
    currentWord.TabWord[4] == 'h'
    ||
    currentWord.Length == 7 &&
    currentWord.TabWord[0] == 'd' &&
    currentWord.TabWord[1] == 'e' &&
    currentWord.TabWord[2] == 'l' &&
    currentWord.TabWord[3] == 'a' &&
    currentWord.TabWord[4] == 'p' &&
    currentWord.TabWord[5] == 'a' &&
    currentWord.TabWord[6] == 'n'
    ||
    currentWord.Length == 8 &&
    currentWord.TabWord[0] == 's' &&
    currentWord.TabWord[1] == 'e' &&
    currentWord.TabWord[2] == 'm' &&
    currentWord.TabWord[3] == 'b' &&
    currentWord.TabWord[4] == 'i' &&
    currentWord.TabWord[5] == 'l' &&
    currentWord.TabWord[6] == 'a' &&
    currentWord.TabWord[7] == 'n'
    ||
    currentWord.Length == 7 &&
    currentWord.TabWord[0] == 's' &&
    currentWord.TabWord[1] == 'e' &&
    currentWord.TabWord[2] == 'p' &&
    currentWord.TabWord[3] == 'u' &&
    currentWord.TabWord[4] == 'l' &&
    currentWord.TabWord[5] == 'u' &&
    currentWord.TabWord[6] == 'h'
    ||
    currentWord.Length == 7 &&
    currentWord.TabWord[0] == 's' &&
    currentWord.TabWord[1] == 'e' &&
    currentWord.TabWord[2] == 'b' &&
    currentWord.TabWord[3] == 'e' &&
    currentWord.TabWord[4] == 'l' &&
    currentWord.TabWord[5] == 'a' &&
    currentWord.TabWord[6] == 's'
    ||
    currentWord.Length == 7 &&
    currentWord.TabWord[0] == 's' &&
    currentWord.TabWord[1] == 'e' &&
    currentWord.TabWord[2] == 'r' &&
    currentWord.TabWord[3] == 'a' &&
    currentWord.TabWord[4] == 't' &&
    currentWord.TabWord[5] == 'u' &&
    currentWord.TabWord[6] == 's';
}
void tulisAngka(int angka) {
    //hitung digit
    if (angka == 0) {
        printf("0");
        return;
    }

    int digit = 0;
    int temp = angka;
    while (temp > 0) {
        temp = temp / 10;
        digit += 1;
    }

    int pembagi = 1;
    int i;
    for (i = 0; i < digit-1; i++) {
        pembagi *= 10;

    }

    while (pembagi > 0) {
        printf("%d", angka/pembagi);
        angka %= pembagi;
        pembagi /= 10;
    }
}
void tulisKata() {
    int i;
    for (i = 0; i < currentWord.Length; i++) {
        printf("%c", currentWord.TabWord[i]);
    }
}
int convertAngka() {
    if (currentWord.Length == 3 &&
    currentWord.TabWord[0] == 'n' &&
    currentWord.TabWord[1] == 'o' &&
    currentWord.TabWord[2] == 'l') return 0;
    if (currentWord.Length == 4 &&
    currentWord.TabWord[0] == 's' &&
    currentWord.TabWord[1] == 'a' &&
    currentWord.TabWord[2] == 't' &&
    currentWord.TabWord[3] == 'u') return 1;
    if (currentWord.Length == 3 &&
    currentWord.TabWord[0] == 'd' &&
    currentWord.TabWord[1] == 'u' &&
    currentWord.TabWord[2] == 'a') return 2;
    if (currentWord.Length == 4 &&
    currentWord.TabWord[0] == 't' &&
    currentWord.TabWord[1] == 'i' &&
    currentWord.TabWord[2] == 'g' &&
    currentWord.TabWord[3] == 'a') return 3;
    if (currentWord.Length == 5 &&
    currentWord.TabWord[0] == 'e' &&
    currentWord.TabWord[1] == 'm' &&
    currentWord.TabWord[2] == 'p' &&
    currentWord.TabWord[3] == 'a' &&
    currentWord.TabWord[4] == 't') return 4;
    if (currentWord.Length == 4 &&
    currentWord.TabWord[0] == 'l' &&
    currentWord.TabWord[1] == 'i' &&
    currentWord.TabWord[2] == 'm' &&
    currentWord.TabWord[3] == 'a') return 5;
    if (currentWord.Length == 4 &&
    currentWord.TabWord[0] == 'e' &&
    currentWord.TabWord[1] == 'n' &&
    currentWord.TabWord[2] == 'a' &&
    currentWord.TabWord[3] == 'm') return 6;
    if (currentWord.Length == 5 &&
    currentWord.TabWord[0] == 't' &&
    currentWord.TabWord[1] == 'u' &&
    currentWord.TabWord[2] == 'j' &&
    currentWord.TabWord[3] == 'u' &&
    currentWord.TabWord[4] == 'h') return 7;
    if (currentWord.Length == 7 &&
    currentWord.TabWord[0] == 'd' &&
    currentWord.TabWord[1] == 'e' &&
    currentWord.TabWord[2] == 'l' &&
    currentWord.TabWord[3] == 'a' &&
    currentWord.TabWord[4] == 'p' &&
    currentWord.TabWord[5] == 'a' &&
    currentWord.TabWord[6] == 'n') return 8;
    if (currentWord.Length == 8 &&
    currentWord.TabWord[0] == 's' &&
    currentWord.TabWord[1] == 'e' &&
    currentWord.TabWord[2] == 'm' &&
    currentWord.TabWord[3] == 'b' &&
    currentWord.TabWord[4] == 'i' &&
    currentWord.TabWord[5] == 'l' &&
    currentWord.TabWord[6] == 'a' &&
    currentWord.TabWord[7] == 'n') return 9;
    if (currentWord.Length == 7 &&
    currentWord.TabWord[0] == 's' &&
    currentWord.TabWord[1] == 'e' &&
    currentWord.TabWord[2] == 'p' &&
    currentWord.TabWord[3] == 'u' &&
    currentWord.TabWord[4] == 'l' &&
    currentWord.TabWord[5] == 'u' &&
    currentWord.TabWord[6] == 'h') return 10;
    if (currentWord.Length == 7 &&
    currentWord.TabWord[0] == 's' &&
    currentWord.TabWord[1] == 'e' &&
    currentWord.TabWord[2] == 'b' &&
    currentWord.TabWord[3] == 'e' &&
    currentWord.TabWord[4] == 'l' &&
    currentWord.TabWord[5] == 'a' &&
    currentWord.TabWord[6] == 's') return 11;
    if (currentWord.Length == 7 &&
    currentWord.TabWord[0] == 's' &&
    currentWord.TabWord[1] == 'e' &&
    currentWord.TabWord[2] == 'r' &&
    currentWord.TabWord[3] == 'a' &&
    currentWord.TabWord[4] == 't' &&
    currentWord.TabWord[5] == 'u' &&
    currentWord.TabWord[6] == 's') return 100;
}
void prosesAngka() {
    //seratus empat hari libur musim panas.
    //seratus empat.
    //seratus.
    int current_angka, result;
    result = 0;
    while (isAngka() && !EndWord) {
        current_angka = convertAngka();
        ADVWORD();
        if (isBelas()) {
            current_angka += 10;
            ADVWORD();
        }
        else if (isPuluh()) {
            current_angka *= 10;
            ADVWORD();
        }
        else if (isRatus()) {
            current_angka *= 100;
            ADVWORD();
        }
        result += current_angka;
    }
    tulisAngka(result);
}


int main() {
    //satu, dua, tiga, empat, lima, enam, tujuh, delapan, sembilan
    //sebelas, belas
    //sepuluh, puluh
    //seratus, ratus
    STARTWORD();
    while (!EndWord) {
        if (isAngka()) {
            prosesAngka();
        } else {
            tulisKata();
            ADVWORD();
        }
        if (!EndWord) {
            printf(" ");
        }
        
    }
    printf("\n");
    return 0;
}