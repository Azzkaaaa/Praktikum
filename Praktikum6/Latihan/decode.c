#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "boolean.h"
#include "stack.h"

// Fungsi untuk membalik string
void reverseString(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// Fungsi untuk mengulangi string sebanyak count kali
void repeatString(char *dest, char *src, int count) {
    dest[0] = '\0';
    for (int i = 0; i < count; i++) {
        strcat(dest, src);
    }
}

int main()
{
    int N;
    char ch;
    Stack stack;
    Stack repeatStack;
    CreateEmpty(&stack);
    CreateEmpty(&repeatStack);

    // Membaca panjang input
    scanf("%d\n", &N);

    char encoded[MaxEl];
    int index = 0; // index untuk posisi encoded

    while ((ch = getchar()) != '\n') {
        encoded[index++] = ch;
    }
    encoded[index] = '\0';

    // Dekode
    char temp[MaxEl];
    char tempStr[MaxEl];
    int repeat = 0;

    for (int i = 0; i < strlen(encoded); i++) {
        ch = encoded[i];

        // Jika karakter adalah digit (pengulangan)
        if (isdigit(ch)) {
            repeat = repeat * 10 + (ch - '0');
        }
        else if (ch == '[') {
            Push(&repeatStack, repeat); // Simpan pengulangan
            repeat = 0; // Reset repeat
            Push(&stack, ch); // Simpan karakter '[' ke stack
        }
        else if (ch == ']') {
            int k = 0;
            while (!IsEmpty(stack) && InfoTop(stack) != '[') {
                temp[k++] = InfoTop(stack);
                Pop(&stack, &temp[k - 1]);
            }
            Pop(&stack, &temp[k]); // Hapus '['
            temp[k] = '\0';
            reverseString(temp);

            infotype count; // Ubah tipe menjadi infotype (char) sesuai dengan deklarasi fungsi Pop
            Pop(&repeatStack, &count);

            repeatString(tempStr, temp, count);

            for (int j = 0; j < strlen(tempStr); j++) {
                Push(&stack, tempStr[j]);
            }
        }
        else {
            Push(&stack, ch);
        }
    }

    // Print hasil decoded dari stack
    int length = Top(stack) + 1;
    for (int i = 0; i < length; i++) {
        printf("%c", stack.T[i]);
    }
    printf("\n");

    return 0;
}
