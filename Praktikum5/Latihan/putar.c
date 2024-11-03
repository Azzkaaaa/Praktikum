#include <stdio.h>
#include <string.h>
#include "mesinkata.h"  // Pastikan untuk menyertakan header mesinkata.h dan mesinkarakter.h

// Fungsi untuk membalikkan kata
void ReverseWord(Word *w) {
    int i = 0;
    int j = w->Length - 1;
    while (i < j) {
        char temp = w->TabWord[i];
        w->TabWord[i] = w->TabWord[j];
        w->TabWord[j] = temp;
        i++;
        j--;
    }
}

int main() {
    STARTWORD();  // Mulai membaca kata
    int wordCount = 1;  // Mulai menghitung kata dari 1
    
    while (!EndWord) {
        if (wordCount % 2 != 0) {
            // Kata pada posisi ganjil, dibalik
            ReverseWord(&currentWord);
        }
        
        // Tampilkan kata yang telah diproses
        for (int i = 0; i < currentWord.Length; i++) {
            printf("%c", currentWord.TabWord[i]);
        }
        
        wordCount++;
        ADVWORD();  // Pindah ke kata berikutnya
        
        // Tambahkan spasi jika masih ada kata berikutnya
        if (!EndWord) {
            printf(" ");
        }
    }
    printf("\n");  // Newline di akhir keluaran
    return 0;
}
