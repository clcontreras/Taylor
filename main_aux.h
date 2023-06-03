//
// Created by Claudio on 01/06/23.
//

#ifndef TAYLOR_MAIN_AUX_H
#define TAYLOR_MAIN_AUX_H
double fxy(double x, double y);

double partial_x_fxy(double x, double y);

double partial_y_fxy(double x, double y);

double second_partial_x_fxy(double x, double y);

double second_partial_y_fxy(double x, double y);

double second_partial_y_x_fxy(double x, double y);

double first_deriv_x_fxy(double x, double y);

double second_deriv_x_fxy(double x, double y);

double Euler(double x0, double y0, double h);

double Taylor_second_order(double x0, double y0, double h);

double Taylor_third_order(double x0, double y0, double h);

void EulerSolution(double x0, double y0, double h, unsigned int n);

double modifiedEuler(double x0, double y0, double h);

void TaylorSecondOrderSolution(double x0, double y0, double h, unsigned int n);

void TaylorThirdOrderSolution(double x0, double y0, double h, unsigned int n);

void modifiedEulerSolution(double x0, double y0, double h, unsigned int n);


#endif //TAYLOR_MAIN_AUX_H
