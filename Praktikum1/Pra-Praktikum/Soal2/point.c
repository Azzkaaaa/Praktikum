#include "point.h"
#include "boolean.h"
#include <stdio.h>
#include <math.h>


void CreatePoint(POINT * P, float X, float Y){
    Absis(*P) = X;
    Ordinat(*P) = Y;
}

void BacaPOINT (POINT * P){
    float X;
    float Y;
    scanf("%f", &X);
    scanf("%f", &Y);
    CreatePoint(P, X, Y);
}

void TulisPOINT (POINT P){
    printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}

boolean EQ (POINT P1, POINT P2){
    return ((Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2)));
}

boolean NEQ (POINT P1, POINT P2){
    return ((Absis(P1) != Absis(P2)) || (Ordinat(P1) != Ordinat(P2)));
}

boolean IsOrigin (POINT P){
    return ((Absis(P) == 0) && (Ordinat(P) == 0));
}

boolean IsOnSbX (POINT P){
    return (Ordinat(P) == 0);
}

boolean IsOnSbY (POINT P){
    return (Absis(P) == 0);
}

int Kuadran (POINT P){
    if (Absis(P) > 0 && Ordinat(P) > 0){
        return 1;
    }else if (Absis(P) < 0 && Ordinat(P) > 0){
        return 2;
    }else if (Absis(P) < 0 && Ordinat(P) < 0){
        return 3;
    }else if (Absis(P) > 0 && Ordinat(P) < 0){
        return 4;
    }
    
}

POINT NextX (POINT P){
    POINT result;
    float X;
    X = Absis(P) + 1.0;
    CreatePoint(&result, X, Ordinat(P));
    return result;
}

POINT NextY (POINT P){
    POINT result;
    float Y;
    Y = Ordinat(P) + 1.0;
    CreatePoint(&result, Absis(P), Y);
    return result;
}

POINT PlusDelta (POINT P, float deltaX, float deltaY){
    POINT result;
    CreatePoint(&result, Absis(P) + deltaX, Ordinat(P) + deltaY);
    return result;
}

POINT MirrorOf (POINT P, boolean SbX){
    POINT result;
    if (SbX == true){
        CreatePoint(&result, Absis(P), -Ordinat(P));
    }else {
        CreatePoint(&result, -Absis(P), Ordinat(P));
    }
    return result;
}

float Jarak0 (POINT P){
    return sqrt(Absis(P) * Absis(P) + Ordinat(P) * Ordinat(P));
}

float Panjang (POINT P1, POINT P2){
    float deltaX;
    float deltaY;
    deltaX = Absis(P2) - Absis(P1);
    deltaY = Ordinat(P2) - Ordinat(P1);
    return sqrt(deltaX * deltaX + deltaY * deltaY);
}

void Geser (POINT *P, float deltaX, float deltaY){
    Absis(*P) = Absis(*P) + deltaX;
    Ordinat(*P) = Ordinat(*P) + deltaY;

}

void GeserKeSbX (POINT *P){
    Ordinat(*P) = 0.0;
}

void GeserKeSbY (POINT *P){
    Absis(*P) = 0.0;
}

void Mirror (POINT *P, boolean SbX){
    if (SbX == true){
        Ordinat(*P) = -Ordinat(*P);
    }else {
        Absis(*P) = -Absis(*P);
    }
}

void Putar (POINT *P, float Sudut){
    float rad;
    float X;
    float Y;
    rad = Sudut * 3.14159265358979323846 / 180.0;
    X = Absis(*P);
    Y = Ordinat(*P);
    Absis(*P) = X * cos(rad) + Y * sin(rad);
    Ordinat(*P) = -X * sin(rad) + Y * cos(rad);
}

void PersamaanLinearDuaVariabel (POINT P1, POINT P2){
    int a;
    int b;
    a = (int)((Ordinat(P2) - Ordinat(P1)) / (Absis(P2) - Absis(P1)));
    b = (int)(Ordinat(P1) - a * Absis(P1));
    printf("(%d,%d)", a, b);
}