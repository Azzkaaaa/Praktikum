#include "circle.h"
#include <stdio.h>
#include <math.h>
#define PI 3.14


boolean IsCIRCLEValid(float X, float Y, float R){
    return R > 0;
}

void CreateCIRCLE(CIRCLE *C, float X, float Y, float R){
    if (IsCIRCLEValid(X, Y, R)) {
        CreatePoint(&Center(*C), X, Y);  // Menggunakan CreatePoint dari point.h
        Radius(*C) = R;
    }
}

void ReadCIRCLE(CIRCLE *C){
    float X;
    float Y;
    float R;
    do{
        scanf("%f %f %f", &X, &Y, &R);
        if (!IsCIRCLEValid(X, Y, R)) {
            printf("CIRCLE tidak valid\n");
        }
    }while(!IsCIRCLEValid(X, Y, R));
    CreateCIRCLE(C, X, Y, R);
}

void WriteCIRCLE(CIRCLE C){
    printf("P(%.2f,%.2f) r=%.2f", Absis(Center(C)), Ordinat(Center(C)), Radius(C));
}

float Circumference(CIRCLE C){
    return 2 * PI * Radius(C);
}

float Area(CIRCLE C){
    return PI * Radius(C) * Radius(C);
}

boolean IsPOINTInsideCIRCLE(CIRCLE C, POINT P){
    float jarak;
    jarak = Panjang(Center(C), P);
    return (jarak < Radius(C));
}

boolean IsPOINTInEdgeCIRCLE(CIRCLE C, POINT P){
    float jarak;
    jarak = Panjang(Center(C), P);
    return (fabs(jarak - Radius(C)) < 0.01);
}

boolean IsCIRCLEInsideCIRCLE(CIRCLE C1, CIRCLE C2){
    float jarak;
    jarak = Panjang(Center(C1), Center(C2));
    return (jarak < fabs(Radius(C2) - Radius(C1)));
}

boolean IsCIRCLESTangents(CIRCLE C1, CIRCLE C2){
    float jarak;
    jarak = Panjang(Center(C1), Center(C2));
    return (fabs(jarak - (Radius(C1) + Radius(C2))) < 0.01 || fabs(jarak - fabs(Radius(C1) - Radius(C2))) < 0.01);
}

boolean IsCIRCLESIntersects(CIRCLE C1, CIRCLE C2){
    float jarak;
    jarak = Panjang(Center(C1), Center(C2));
    return (fabs(Radius(C1) - Radius(C2)) < jarak && jarak < (Radius(C1) + Radius(C2)));
}