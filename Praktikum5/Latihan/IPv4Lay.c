#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "mesinkata.h"

// Fungsi untuk memeriksa apakah sebuah string berisi angka saja
bool isNumeric(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return false;
        }
    }
    return true;
}

// Fungsi untuk memeriksa apakah oktet valid (tanpa leading zero dan dalam rentang 0-255)
bool isValidOctet(char *octet) {
    if (!isNumeric(octet)) return false;
    
    int len = strlen(octet);
    if (len > 1 && octet[0] == '0') return false; // Cek leading zero
    
    int num = atoi(octet);
    return num >= 0 && num <= 255;
}

// Fungsi untuk memeriksa apakah sebuah kata adalah IPv4Lay
bool isIPv4Lay(Word word) {
    char temp[51];
    strncpy(temp, word.TabWord, word.Length);
    temp[word.Length] = '\0';  // Mengakhiri string dengan null terminator
    
    // Split berdasarkan '@'
    char *octet = strtok(temp, "@");
    int count = 0;
    
    while (octet != NULL) {
        if (!isValidOctet(octet)) return false;
        count++;
        octet = strtok(NULL, "@");
    }
    
    return count == 4;  // Harus ada tepat 4 oktet
}

int main() {
    STARTWORD();
    
    while (!EndWord) {
        if (isIPv4Lay(currentWord)) {
            printf("4Lay");
        } else {
            printf("ewh");
        }
        
        ADVWORD();
        
        if (!EndWord) {
            printf(" ");
        }
    }
    
    printf("\n");  // Newline di akhir keluaran
    return 0;
}
