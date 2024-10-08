#include <stdio.h>
#include "complex.h"
int main(){
    COMPLEX C1;
    COMPLEX C2;
    BacaCOMPLEX(&C1);
    printf("C1 : ");
    TulisCOMPLEX(C1);

    BacaCOMPLEX(&C2);
    printf("C2 : ");
    TulisCOMPLEX(C2);

    printf("C1 + C2 = \n");
    AddCOMPLEX(C1, C2);

    printf("C1 - C2 = \n");
    SubtractCOMPLEX(C1, C2);

    printf("C1 x C2 = \n");
    MultiplyCOMPLEX(C1, C2);

    printf("C1 / C2 = ");
    DivideCOMPLEX(C1, C2);

    printf("Nilai absolute C1 = ");
    AbsCOMPLEX(C1);

    printf("Nilai absolute C2 = ");
    AbsCOMPLEX(C2);

    printf("Konjungation C1 = ");
    ConjugateCOMPLEX(C1);
    
    printf("Konjungation C1 = ");
    ConjugateCOMPLEX(C1);

    printf("Apakah C1 = C2 ? ");
    CEQ(C1,C2);

    printf("Apakah C1 != C2 ? ");
    CNEQ(C1, C2);
}