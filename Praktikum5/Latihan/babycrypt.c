#include <stdio.h>
#include <ctype.h>
#include "mesinkata.h"

// Fungsi untuk mendekripsi satu karakter
char decryptChar(char ch, int shift) {
    if (ch >= 'A' && ch <= 'Z') {
        return ((ch - 'A' - shift + 26) % 26) + 'A';
    } else if (ch >= 'a' && ch <= 'z') {
        return ((ch - 'a' - shift + 26) % 26) + 'a';
    }
    return ch;  // Karakter non-alfabet tidak berubah
}

// Fungsi untuk mendekripsi kata
void decryptWord(Word *w, int shift) {
    for (int i = 0; i < w->Length; i++) {
        w->TabWord[i] = decryptChar(w->TabWord[i], shift);
    }
}

int main() {
    STARTWORD();  // Memulai pembacaan kata pertama (nilai shift)
    
    // Ambil nilai shift dari kata pertama
    int shift = 0;
    for (int i = 0; i < currentWord.Length; i++) {
        shift = shift * 10 + (currentWord.TabWord[i] - '0');
    }
    
    // Normalisasi shift agar dalam rentang 0-25
    shift = shift % 26;
    
    ADVWORD();  // Pindah ke kata berikutnya yang merupakan pesan terenkripsi

    while (!EndWord) {
        // Dekripsi kata saat ini
        decryptWord(&currentWord, shift);
        
        // Cetak kata yang telah didekripsi
        for (int i = 0; i < currentWord.Length; i++) {
            printf("%c", currentWord.TabWord[i]);
        }

        ADVWORD();  // Pindah ke kata berikutnya
        
        // Tambahkan spasi jika masih ada kata berikutnya
        if (!EndWord) {
            printf(" ");
        }
    }
    
    printf("\n");  // Newline di akhir keluaran
    return 0;
}
