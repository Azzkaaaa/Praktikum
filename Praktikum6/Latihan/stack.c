#include <stdio.h>
#include "stack.h"


void CreateEmpty(Stack *S){
    Top(*S) = Nil;
}

boolean IsEmpty(Stack S){
    return Top(S) == Nil;
}

boolean IsFull(Stack S){
    return Top(S) == MaxEl - 1;
}

void Push(Stack * S, infotype X){
    Top(*S)++;
    (*S).T[Top(*S)] = X;
}

void Pop(Stack * S, infotype* X){
    *X = (*S).T[Top(*S)];
    Top(*S)--;
}