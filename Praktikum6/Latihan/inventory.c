#include <stdio.h>
#include "boolean.h"
#include "stack.h"

int main()
{
    int N, i, temp;
    char ch;
    Stack s;
    CreateEmpty(&s);

    scanf("%d", &N);

    for (i = 0; i < N; i++)
    {
        scanf(" %c", &ch);

        if (ch >= '0' && ch <= '9') {
            // Tambahkan angka ke stack
            Push(&s, ch - '0');
        }
        else if (ch == '+') {
            // Tambahkan jumlah dua elemen teratas
            int top1, top2;
            Pop(&s, &top1);
            Pop(&s, &top2);
            int sum = top1 + top2;
            Push(&s, top2);  // Kembalikan elemen yang di-pop
            Push(&s, top1);  // Kembalikan elemen yang di-pop
            Push(&s, sum);   // Tambahkan hasil penjumlahan
        }
        else if (ch == 'X') {
            // Batalkan elemen terakhir
            int removed;
            Pop(&s, &removed);
        }
        else if (ch == 'S') {
            // Tambahkan total ke stack, lalu hapus semua elemen
            int sum = 0;
            while (!IsEmpty(s)) {
                int top;
                Pop(&s, &top);
                sum += top;
            }
            Push(&s, sum);
        }
        else if (ch == 'A') {
            // Tambahkan rata-rata ke stack, lalu hapus semua elemen
            int sum = 0, count = 0;
            while (!IsEmpty(s)) {
                int top;
                Pop(&s, &top);
                sum += top;
                count++;
            }
            int avg = sum / count;  // Rata-rata dibulatkan ke bawah
            Push(&s, avg);
        }
    }

    // Hitung total barang dalam stack
    int total = 0;
    while (!IsEmpty(s)) {
        int top;
        Pop(&s, &top);
        total += top;
    }

    printf("%d\n", total);
    return 0;
}
