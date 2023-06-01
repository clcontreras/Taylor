//
// Created by Claudio on 01/06/23.
//

#include "main_aux.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double fxy(double x, double y) {
    return x-y;
}

double dfxy(double x, double y) {
    return 1-fxy(x,y);
}

double Euler(double x0, double y0, double h) {
    return y0+h*fxy(x0,y0);
}

void EulerSolution(double x0, double y0, double h, unsigned int n){
    FILE *fp;
    fp = fopen("../EulerSolution.dat", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    double x = x0;
    double y = y0;
    fprintf(fp, "%f %f\n", x, y);
    printf("\t%f %f\n", x, y);
    for (int i = 0; i < n; i++) {
        y = Euler(x,y,h);
        x += h;
        fprintf(fp, "%f %f\n", x, y);
        printf("\t%f %f\n", x, y);
    }
    fclose(fp);
}
