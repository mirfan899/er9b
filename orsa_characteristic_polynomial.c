#include "header.h"
#include "proto.h"

void orsa_characteristic_polynomial(
 double F1[3*3],
 double F2[3*3],
 double a[4]
)

{

    a[0] = 0.0;
    a[1] = 0.0;
    a[2] = 0.0;
    a[3] = 0.0;
    for(int i0=0; i0 < 3; i0++) { // Even permutations
        int i1 = (i0+1)%3;
        int i2 = (i1+1)%3;
        a[0] += F1[i0*3+0]*F1[i1*3+1]*F1[i2*3+2];
        a[1] += F2[i0*3+0]*F1[i1*3+1]*F1[i2*3+2]+
                F1[i0*3+0]*F2[i1*3+1]*F1[i2*3+2]+
                F1[i0*3+0]*F1[i1*3+1]*F2[i2*3+2];
        a[2] += F1[i0*3+0]*F2[i1*3+1]*F2[i2*3+2]+
                F2[i0*3+0]*F1[i1*3+1]*F2[i2*3+2]+
                F2[i0*3+0]*F2[i1*3+1]*F1[i2*3+2];
        a[3] += F2[i0*3+0]*F2[i1*3+1]*F2[i2*3+2];
    }
    for(int i0=0; i0 < 3; i0++) { // Odd permutations
        int i1 = (i0+2)%3;
        int i2 = (i1+2)%3;
        a[0] -= F1[i0*3+0]*F1[i1*3+1]*F1[i2*3+2];
        a[1] -= F2[i0*3+0]*F1[i1*3+1]*F1[i2*3+2]+
                F1[i0*3+0]*F2[i1*3+1]*F1[i2*3+2]+
                F1[i0*3+0]*F1[i1*3+1]*F2[i2*3+2];
        a[2] -= F1[i0*3+0]*F2[i1*3+1]*F2[i2*3+2]+
                F2[i0*3+0]*F1[i1*3+1]*F2[i2*3+2]+
                F2[i0*3+0]*F2[i1*3+1]*F1[i2*3+2];
        a[3] -= F2[i0*3+0]*F2[i1*3+1]*F2[i2*3+2];
    }

}
