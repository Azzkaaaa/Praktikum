#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "boolean.h"

const int MXN = 100;
int dRow[] = {0, 0, 1, -1};
int dCol[] = {1, -1, 0, 0};

int main() {
    Queue q;
    int N;
    char arr[MXN][MXN];
    int dist[MXN][MXN]; 
    scanf("%d", &N);
    CreateQueue(&q);

    ElType start, end;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf(" %c", &arr[i][j]);
            dist[i][j] = -1; 
            if (arr[i][j] == 'A') {
                start.row = i;
                start.col = j;
            }
            if (arr[i][j] == 'B') {
                end.row = i;
                end.col = j;
            }
        }
    }
    enqueue(&q, start);
    dist[start.row][start.col] = 0;
    while (!isEmpty(q)) {
        ElType current;
        dequeue(&q, &current);
        if (arr[current.row][current.col] == 'B') {
            printf("Ya\n");
            printf("%d\n", dist[current.row][current.col]);
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            int newRow = current.row + dRow[i];
            int newCol = current.col + dCol[i];
            if (newRow >= 0 && newRow < N && newCol >= 0 && newCol < N &&
                arr[newRow][newCol] != '#' && dist[newRow][newCol] == -1) {
                ElType next = {newRow, newCol};
                enqueue(&q, next);
                dist[newRow][newCol] = dist[current.row][current.col] + 1;
            }
        }
    }


    printf("Tidak\n");
    return 0;
}
