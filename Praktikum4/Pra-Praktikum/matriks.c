#include "matriks.h"
#include <stdio.h>

void createMatrix(int nRows, int nCols, Matrix *m){
    ROW_EFF(*m) = nRows;
    COL_EFF(*m) = nCols;
}

boolean isMatrixIdxValid(int i, int j){
    return(i <= 0 && j <= 0);
}

IdxType getLastIdxRow(Matrix m){
    return ROW_EFF(m) - 1;
}

IdxType getLastIdxCol(Matrix m){
    return COL_EFF(m) - 1;
}

boolean isIdxEff(Matrix m, IdxType i, IdxType j){
    return (ELMT(m, i, j) == ELMT(m, ROW_EFF(m) - 1, COL_EFF(m) - 1));
}

ElType getElmtDiagonal(Matrix m, IdxType i){
    return ELMT(m, i, i);
}

void copyMatrix(Matrix mIn, Matrix *mOut){
    int i;
    int j;
    for (i = 0; i < ROW_EFF(mIn); i++){
        for (j = 0; j < COL_EFF(mIn); j++){
            ELMT(*mOut, i, j) = ELMT(mIn, i, j);
        }
    }
}

void readMatrix(Matrix *m, int nRow, int nCol){
    int i;
    int j;
    isMatrixIdxValid(nRow, nCol);
    createMatrix(m, nRow, nCol);
    for (i = 0; i < ROW_EFF(*m); i++){
        for (j = 0; j < COL_EFF(*m); j++){
            scanf("%d", &ELMT(*m, i, j));
        }
    }
}

void displayMatrix(Matrix m){
    int i;
    int j;
    for (i = 0; i < ROW_EFF(m); i++){
        for (j = 0; j < COL_EFF(m); j++){
            printf("%d", ELMT(m, i, j));
            if (j != getLastIdxCol(m) - 1){
                printf(" ");
            }
        }
        printf("\n");
    }
}

Matrix addMatrix(Matrix m1, Matrix m2){
    int i;
    int j;
    Matrix result;
    createMatrix(&result, ROW_EFF(m1), COL_EFF(m1));
    for (i = 0; i < ROW_EFF(m1); i++){
        for (j = 0; j < COL_EFF(m1); j++){
            ELMT(result, i, j) = ELMT(m1, i, j) + ELMT(m2, i, j);
        }
    }
    return result;
}

Matrix subtractMatrix(Matrix m1, Matrix m2){
    int i;
    int j;
    Matrix result;
    createMatrix(&result, ROW_EFF(m1), COL_EFF(m1));
    for (i = 0; i < ROW_EFF(m1); i++){
        for (j = 0; j < COL_EFF(m1); j++){
            ELMT(result, i, j) = ELMT(m1, i, j) - ELMT(m2, i, j);
        }
    }
    return result;
}

Matrix multiplyMatrix(Matrix m1, Matrix m2){
    int i;
    int j;
    Matrix result;
    createMatrix(&result, ROW_EFF(m1), COL_EFF(m1));
    for (i = 0; i < ROW_EFF(m1); i++){
        for (j = 0; j < COL_EFF(m1); j++){
            ELMT(result, i, j) = ELMT(m1, i, j) * ELMT(m2, i, j);
        }
    }
    return result;
}

Matrix multiplyByConst(Matrix m, ElType x){
    int i;
    int j;
    for (i = 0; i < ROW_EFF(m); i++){
        for (j = 0; j < COL_EFF(m); j++){
            ELMT(m, i, j) = ELMT(m, i, j) * x;
        }
    }
    return m;
}

void pMultiplyByConst(Matrix *m, ElType k){
    int i;
    int j;
    for (i = 0; i < ROW_EFF(*m); i++){
        for (j = 0; j < COL_EFF(*m); j++){
            ELMT(*m, i, j) = ELMT(*m, i, j) * k;
        }
    }
}

boolean isMatrixEqual(Matrix m1, Matrix m2){
    if (getLastIdxCol(m1) != getLastIdxCol(m2) || getLastIdxRow(m1) != getLastIdxRow(m2)){
        return false;
    }
    int i;
    int j;
    for (i = 0; i < getLastIdxRow(m1); i++){
        for (j = 0; j < getLastIdxCol(m1); j++){
            if (ELMT(m1, i, j) != ELMT(m2, i, j)){
                return false;
            }
        }
    }
    return true;
}

boolean isMatrixNotEqual(Matrix m1, Matrix m2){
    return !isMatrixEqual(m1, m2);
}

boolean isMatrixSizeEqual(Matrix m1, Matrix m2){
    return (getLastIdxRow(m1) == getLastIdxRow(m2) && getLastIdxCol(m1) == getLastIdxCol(m2));
}

int countElmt(Matrix m){
    return (getLastIdxCol(m) * getLastIdxRow(m));
}

boolean isSquare(Matrix m){
    return (getLastIdxCol(m) == getLastIdxRow(m));
}

boolean isSymmetric(Matrix m){
    int i;
    int j;
    for (i = 0; i < getLastIdxRow(m); i++){
        for (j = 0; j < getLastIdxRow(m); j++){
            if (ELMT(m, i, j) != ELMT(m, j, i)){
                return false;
            }
        }
    }
    return true;
}

boolean isIdentity(Matrix m){
    int i;
    for (i = 0; i < getLastIdxRow(m); i++){
        if (getElmtDiagonal(m, i) != 1){
            return false;
        }
    }
    return true;
}

boolean isSparse(Matrix m){
    
}

Matrix negation(Matrix m){
    
}