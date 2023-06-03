//
// Created by Claudio on 03/06/23.
//

#include "gsl_ode.h"
#include <stdio.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_odeiv2.h>

int func (double x, const double y[], double f[], void *params)
{
    f[0] = x-y[0];
    return GSL_SUCCESS;
}


int gslSolution1d (double x0, double y0, double h, unsigned int n){
    FILE *fp;
    fp = fopen("../gsl_rk4.dat", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    gsl_odeiv2_system sys = {func, NULL, 1, NULL};
    gsl_odeiv2_driver * d = gsl_odeiv2_driver_alloc_y_new (&sys, gsl_odeiv2_step_rk4, h, 1e-3, 0);
    double x = x0;
    double y[1] = { y0 };
    printf("\t%.8e %.8e\n", x, y[0]);
    int status;
    for (int i = 1; i <= n; i++)
    {
        status = gsl_odeiv2_driver_apply_fixed_step (d, &x, h, 1, y);
        if (status != GSL_SUCCESS)
        {
            printf ("error, return value=%d\n", status);
            break;
        }
        fprintf(fp, "%.8e %.8e\n", x, y[0]);
        printf("\t%.8e %.8e\n", x, y[0]);
    }
    gsl_odeiv2_driver_free (d);
    fclose(fp);
    return 0;
}
