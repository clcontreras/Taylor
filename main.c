#include <stdio.h>
#include "main_aux.h"

int main() {
    unsigned int n = 5;
    double h=0.2;
    double x0=0;
    double y0=2;
    printf("Euler Solution:\n");
    EulerSolution(x0,y0,h,n);
    printf("Taylor Second Order Solution:\n");
    TaylorSecondOrderSolution(x0,y0,h,n);
    printf("Taylor Third Order Solution:\n");
    TaylorThirdOrderSolution(x0,y0,h,n);
    return 0;
}
