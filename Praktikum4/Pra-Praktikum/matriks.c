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
    isMatrixIdxValid(nRow, nCol);
    createMatrix(m, nRow, nCol);
}