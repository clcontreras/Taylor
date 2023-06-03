//
// Created by Claudio on 03/06/23.
//

#ifndef TAYLOR_GSL_ODE_H
#define TAYLOR_GSL_ODE_H
int func (double x, const double y[], double f[], void *params);
int gslSolution1d (double x0, double y0, double h, unsigned int n);
#endif //TAYLOR_GSL_ODE_H
