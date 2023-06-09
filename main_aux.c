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

double partial_x_fxy(double x, double y) {
    return 1;
}

double partial_y_fxy(double x, double y) {
    return -1;
}

double first_deriv_x_fxy(double x, double y) {
    return partial_x_fxy(x,y)+fxy(x,y)*partial_y_fxy(x,y);
}

double second_partial_x_fxy(double x, double y) {
    return 0;
}

double second_partial_y_fxy(double x, double y) {
    return 0;
}

double second_partial_y_x_fxy(double x, double y) {
    return 0;
}

double second_deriv_x_fxy(double x, double y) {
    return second_partial_x_fxy(x,y)+
    partial_x_fxy(x,y)*partial_y_fxy(x,y)+
    2*fxy(x,y)*second_partial_y_x_fxy(x,y)+
    fxy(x,y)*partial_y_fxy(x,y)*partial_y_fxy(x,y)+
    fxy(x,y)*fxy(x,y)*second_partial_y_fxy(x,y);
}

double Euler(double x0, double y0, double h) {
    return y0+h*fxy(x0,y0);
}

double Taylor_second_order(double x0, double y0, double h) {
    return y0+h*fxy(x0,y0)+h*h/2*first_deriv_x_fxy(x0,y0);
}

double Taylor_third_order(double x0, double y0, double h) {
    return y0+h*fxy(x0,y0)+h*h/2*first_deriv_x_fxy(x0,y0)+h*h*h/6*second_deriv_x_fxy(x0,y0);
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

void TaylorSecondOrderSolution(double x0, double y0, double h, unsigned int n){
    FILE *fp;
    fp = fopen("../TaylorSecondOrderSolution.dat", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    double x = x0;
    double y = y0;
    fprintf(fp, "%f %f\n", x, y);
    printf("\t%f %f\n", x, y);
    for (int i = 0; i < n; i++) {
        y = Taylor_second_order(x,y,h);
        x += h;
        fprintf(fp, "%f %f\n", x, y);
        printf("\t%f %f\n", x, y);
    }
    fclose(fp);
}

void TaylorThirdOrderSolution(double x0, double y0, double h, unsigned int n){
    FILE *fp;
    fp = fopen("../TaylorThirdOrderSolution.dat", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    double x = x0;
    double y = y0;
    fprintf(fp, "%f %f\n", x, y);
    printf("\t%f %f\n", x, y);
    for (int i = 0; i < n; i++) {
        y = Taylor_third_order(x,y,h);
        x += h;
        fprintf(fp, "%f %f\n", x, y);
        printf("\t%f %f\n", x, y);
    }
    fclose(fp);
}

double modifiedEuler(double x0, double y0, double h) {
    double k1 = fxy(x0,y0);
    double k2 = fxy(x0+h,y0+h*k1);
    return y0+h/2*(k1+k2);
}

void modifiedEulerSolution(double x0, double y0, double h, unsigned int n){
    FILE *fp;
    fp = fopen("../ModifiedEulerSolution.dat", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    double x = x0;
    double y = y0;
    fprintf(fp, "%f %f\n", x, y);
    printf("\t%f %f\n", x, y);
    for (int i = 0; i < n; i++) {
        y = modifiedEuler(x,y,h);
        x += h;
        fprintf(fp, "%f %f\n", x, y);
        printf("\t%f %f\n", x, y);
    }
    fclose(fp);
}

double RK4(double x0, double y0, double h) {
    double k1 = fxy(x0,y0);
    double k2 = fxy(x0+h/2,y0+h/2*k1);
    double k3 = fxy(x0+h/2,y0+h/2*k2);
    double k4 = fxy(x0+h,y0+h*k3);
    return y0+h/6*(k1+2*k2+2*k3+k4);
}

void RK4Solution(double x0, double y0, double h, unsigned int n){
    FILE *fp;
    fp = fopen("../RK4Solution.dat", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    double x = x0;
    double y = y0;
    fprintf(fp, "%f %f\n", x, y);
    printf("\t%f %f\n", x, y);
    for (int i = 0; i < n; i++) {
        y = RK4(x,y,h);
        x += h;
        fprintf(fp, "%f %f\n", x, y);
        printf("\t%f %f\n", x, y);
    }
    fclose(fp);
}
