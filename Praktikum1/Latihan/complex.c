#include "complex.h"
#include "boolean.h"
#include <stdio.h>


boolean IsCOMPLEXValid(float Re, float Im){
    return true;
}

void CreateComplex(COMPLEX *C, float Re, float Im){
    Real(*C) = Re;
    Imag(*C) = Im;
    
}

void BacaCOMPLEX(COMPLEX *C){
    float Re;
    float Im;
    scanf("%f", &Re);
    scanf("%f", &Im);
    CreateComplex(C, Re, Im);
    

}

void TulisCOMPLEX(COMPLEX C){
    float Re;
    float Im;
    
    printf("%.2f%+.2fi\n", Real(C), Imag(C));

    

}

COMPLEX AddCOMPLEX(COMPLEX C1, COMPLEX C2){
    COMPLEX result;
    float Re;
    float Im;
    Re = Real(C1) + Real(C2);
    Im = Imag(C1) + Imag(C2);
    CreateComplex(&result, Re, Im);
    return result;
}

COMPLEX SubtractCOMPLEX(COMPLEX C1, COMPLEX C2){
    COMPLEX result;
    float Re;
    float Im;
    Re = Real(C1) - Real(C2);
    Im = Imag(C1) - Imag(C2);
    CreateComplex(&result, Re, Im);
    return result;
}

COMPLEX MultiplyCOMPLEX(COMPLEX C1, COMPLEX C2){
    COMPLEX result;
    float Re;
    float Im;
    Re = (Real(C1) * Real(C2)) - (Imag(C2) * Imag(C1));
    Im = (Real(C1) * Imag(C2)) + (Real(C2) * Imag(C1));
    CreateComplex(&result, Re, Im);
    return result;
}

COMPLEX DivideCOMPLEX(COMPLEX C1, COMPLEX C2){
    COMPLEX result;
    float is0;
    float Re;
    float Im;
    is0 = (Real(C2) * Real(C2)) + (Imag(C2) * Imag(C2));
    if(is0 <= 0){
        CreateComplex(&result, 0.0, 0.0);
        return result;
    }else{
        Re = (Real(C1) * Real(C2) + Imag(C1) * Imag(C2)) / is0;
        Im = (Imag(C1) * Real(C2) - Real(C1) * Imag(C2)) / is0;
        CreateComplex(&result, Re, Im);
    }
    return result;
    
}

float AbsCOMPLEX(COMPLEX C){
    return sqrt(Real(C) * Real(C) + Imag(C) * Imag(C));
}

COMPLEX ConjugateCOMPLEX(COMPLEX C){
    COMPLEX result;
    float Re;
    float Im;
    Re = Real(C);
    Im = -Imag(C);
    CreateComplex(&result, Re, Im);
    return result;
}

boolean CEQ(COMPLEX C1, COMPLEX C2){
    return (Real(C1) == Real(C2) && Imag(C1) == Imag(C2));
}

boolean CNEQ(COMPLEX C1, COMPLEX C2){
    return (Real(C1) != Real(C2) || Imag(C1) != Imag(C2));
}