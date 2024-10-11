#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "matrix.h"

/* *** Konstruktor membentuk Matrix *** */
void createMatrix(int nRows, int nCols, Matrix *m) {
    ROW_EFF(*m) = nRows;
    COL_EFF(*m) = nCols;
}

/* *** Selektor "Dunia Matrix" *** */
boolean isMatrixIdxValid(int i, int j) {
    return (i >= 0 && i < ROW_CAP && j >= 0 && j < COL_CAP);
}

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IdxType getLastIdxRow(Matrix m) {
    return ROW_EFF(m) - 1;
}

IdxType getLastIdxCol(Matrix m) {
    return COL_EFF(m) - 1;
}

boolean isIdxEff(Matrix m, IdxType i, IdxType j) {
    return (i >= 0 && i < ROW_EFF(m) && j >= 0 && j < COL_EFF(m));
}

ElType getElmtDiagonal(Matrix m, IdxType i) {
    return ELMT(m, i, i);
}

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mOut) {
    createMatrix(ROW_EFF(mIn), COL_EFF(mIn), mOut);
    for (int i = 0; i < ROW_EFF(mIn); i++) {
        for (int j = 0; j < COL_EFF(mIn); j++) {
            ELMT(*mOut, i, j) = ELMT(mIn, i, j);
        }
    }
}

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol) {
    createMatrix(nRow, nCol, m);
    for (int i = 0; i < nRow; i++) {
        for (int j = 0; j < nCol; j++) {
            scanf("%d", &ELMT(*m, i, j));
        }
    }
}

void displayMatrix(Matrix m) {
    for (int i = 0; i < ROW_EFF(m); i++) {
        for (int j = 0; j < COL_EFF(m); j++) {
            printf("%d", ELMT(m, i, j));
            if (j < COL_EFF(m) - 1) {
                printf(" ");
            }
        }
        if (i < ROW_EFF(m) - 1) {
            printf("\n");
        }
    }
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
Matrix addMatrix(Matrix m1, Matrix m2) {
    Matrix result;
    createMatrix(ROW_EFF(m1), COL_EFF(m1), &result);
    for (int i = 0; i < ROW_EFF(m1); i++) {
        for (int j = 0; j < COL_EFF(m1); j++) {
            ELMT(result, i, j) = ELMT(m1, i, j) + ELMT(m2, i, j);
        }
    }
    return result;
}

Matrix subtractMatrix(Matrix m1, Matrix m2) {
    Matrix result;
    createMatrix(ROW_EFF(m1), COL_EFF(m1), &result);
    for (int i = 0; i < ROW_EFF(m1); i++) {
        for (int j = 0; j < COL_EFF(m1); j++) {
            ELMT(result, i, j) = ELMT(m1, i, j) - ELMT(m2, i, j);
        }
    }
    return result;
}

Matrix multiplyMatrix(Matrix m1, Matrix m2) {
    Matrix result;
    createMatrix(ROW_EFF(m1), COL_EFF(m2), &result);
    for (int i = 0; i < ROW_EFF(m1); i++) {
        for (int j = 0; j < COL_EFF(m2); j++) {
            ELMT(result, i, j) = 0; // Initialize element to 0
            for (int k = 0; k < COL_EFF(m1); k++) {
                ELMT(result, i, j) += ELMT(m1, i, k) * ELMT(m2, k, j);
            }
        }
    }
    return result;
}

Matrix multiplyByConst(Matrix m, ElType x) {
    Matrix result;
    createMatrix(ROW_EFF(m), COL_EFF(m), &result);
    for (int i = 0; i < ROW_EFF(m); i++) {
        for (int j = 0; j < COL_EFF(m); j++) {
            ELMT(result, i, j) = ELMT(m, i, j) * x;
        }
    }
    return result;
}

void pMultiplyByConst(Matrix *m, ElType k) {
    for (int i = 0; i < ROW_EFF(*m); i++) {
        for (int j = 0; j < COL_EFF(*m); j++) {
            ELMT(*m, i, j) *= k;
        }
    }
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isMatrixEqual(Matrix m1, Matrix m2) {
    if (!isMatrixSizeEqual(m1, m2)) return false;
    for (int i = 0; i < ROW_EFF(m1); i++) {
        for (int j = 0; j < COL_EFF(m1); j++) {
            if (ELMT(m1, i, j) != ELMT(m2, i, j)) return false;
        }
    }
    return true;
}

boolean isMatrixNotEqual(Matrix m1, Matrix m2) {
    return !isMatrixEqual(m1, m2);
}

boolean isMatrixSizeEqual(Matrix m1, Matrix m2) {
    return (ROW_EFF(m1) == ROW_EFF(m2)) && (COL_EFF(m1) == COL_EFF(m2));
}

/* ********** Operasi lain ********** */
int countElmt(Matrix m) {
    return ROW_EFF(m) * COL_EFF(m);
}

/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquare(Matrix m) {
    return (ROW_EFF(m) == COL_EFF(m));
}

boolean isSymmetric(Matrix m) {
    if (!isSquare(m)) return false;
    for (int i = 0; i < ROW_EFF(m); i++) {
        for (int j = 0; j < i; j++) {
            if (ELMT(m, i, j) != ELMT(m, j, i)) return false;
        }
    }
    return true;
}

boolean isIdentity(Matrix m) {
    if (!isSquare(m)) return false;
    for (int i = 0; i < ROW_EFF(m); i++) {
        for (int j = 0; j < COL_EFF(m); j++) {
            if (i == j) {
                if (ELMT(m, i, j) != 1) return false;
            } else {
                if (ELMT(m, i, j) != 0) return false;
            }
        }
    }
    return true;
}

boolean isSparse(Matrix m) {
    int countNonZero = 0;
    for (int i = 0; i < ROW_EFF(m); i++) {
        for (int j = 0; j < COL_EFF(m); j++) {
            if (ELMT(m, i, j) != 0) {
                countNonZero++;
            }
        }
    }
    return (countNonZero <= 0.05 * countElmt(m)); // 5% dari total elemen
}

Matrix negation(Matrix m) {
    Matrix result;
    createMatrix(ROW_EFF(m), COL_EFF(m), &result);
    for (int i = 0; i < ROW_EFF(m); i++) {
        for (int j = 0; j < COL_EFF(m); j++) {
            ELMT(result, i, j) = -ELMT(m, i, j);
        }
    }
    return result;
}

void pNegation(Matrix *m) {
    for (int i = 0; i < ROW_EFF(*m); i++) {
        for (int j = 0; j < COL_EFF(*m); j++) {
            ELMT(*m, i, j) = -ELMT(*m, i, j);
        }
    }
}

/* Determinan dan Transpose tidak diimplementasikan di sini */


/* Fungsi untuk menghitung determinan matriks */
float determinant(Matrix m) {
    // Prekondisi: isSquare(m) sudah dipastikan
    if (ROW_EFF(m) == 1) {
        return ELMT(m, 0, 0); // Determinan untuk matriks 1x1
    }
    if (ROW_EFF(m) == 2) {
        return ELMT(m, 0, 0) * ELMT(m, 1, 1) - ELMT(m, 0, 1) * ELMT(m, 1, 0); // Determinan untuk matriks 2x2
    }

    float det = 0;
    for (int j = 0; j < COL_EFF(m); j++) {
        // Membuat submatriks
        Matrix subMatrix;
        createMatrix(ROW_EFF(m) - 1, COL_EFF(m) - 1, &subMatrix);
        
        for (int subI = 0; subI < ROW_EFF(m) - 1; subI++) {
            for (int subJ = 0; subJ < COL_EFF(m) - 1; subJ++) {
                if (subJ < j) {
                    ELMT(subMatrix, subI, subJ) = ELMT(m, subI + 1, subJ);
                } else {
                    ELMT(subMatrix, subI, subJ) = ELMT(m, subI + 1, subJ + 1);
                }
            }
        }

        // Menggunakan rumus ekspansi kofaktor
        det += (j % 2 == 0 ? 1 : -1) * ELMT(m, 0, j) * determinant(subMatrix);
    }
    return det;
}

/* Fungsi untuk mentranspose matriks */
Matrix transpose(Matrix m) {
    // I.S. m terdefinisi dan isSquare(m)
    Matrix result;
    createMatrix(ROW_EFF(m), COL_EFF(m), &result);
    
    for (int i = 0; i < ROW_EFF(m); i++) {
        for (int j = 0; j < COL_EFF(m); j++) {
            ELMT(result, j, i) = ELMT(m, i, j); // Transpose: m(i,j) = m(j,i)
        }
    }
    return result;
}

/* Prosedur untuk melakukan transpose matriks secara langsung */
void pTranspose(Matrix *m) {
    // I.S. m terdefinisi dan isSquare(m)
    Matrix temp = transpose(*m);
    copyMatrix(temp, m); // Mengcopy hasil transpose kembali ke m
}