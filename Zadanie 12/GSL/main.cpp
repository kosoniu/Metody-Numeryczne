#include <iostream>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_min.h>

using namespace std;

double fn1 (double x, void * params)
{
    (void)(params); /* avoid unused parameter warning */
    return cos(x) + 1.0;
}

double fx(double x, void * params){
    double a = sqrt(2.0-x*x) / sqrt(2.0);
    double b = (x - 1.0);
    (void)(params);
    return (a - 0.5)*(a - 0.5) + b*b - 1.0/4.0;
}

int
main (void)
{
    int status;
    int iter = 0, max_iter = 100;
    const gsl_min_fminimizer_type *T;
    gsl_min_fminimizer *s;
    double m = -1.0;
    double a = 0.0;
    double b = 3.0;
    gsl_function F;

    F.function = &fx;
    F.params = 0;

    T = gsl_min_fminimizer_brent;
    s = gsl_min_fminimizer_alloc (T);
    gsl_min_fminimizer_set (s, &F, m, a, b);

//    printf ("using %s method\n",
//            gsl_min_fminimizer_name (s));
//
//    printf ("%5s [%9s, %9s] %9s %10s %9s\n",
//            "iter", "lower", "upper", "min",
//            "err", "err(est)");
//
//    printf ("%5d [%.7f, %.7f] %.7f %+.7f %.7f\n",
//            iter, a, b,
//            m, m - m_expected, b - a);

    do
    {
        iter++;
        status = gsl_min_fminimizer_iterate (s);

        m = gsl_min_fminimizer_x_minimum (s);
        a = gsl_min_fminimizer_x_lower (s);
        b = gsl_min_fminimizer_x_upper (s);

        status
                = gsl_min_test_interval (a, b, 0.001, 0.0);

        if (status == GSL_SUCCESS)
            printf ("Converged:\n");

    }
    while (status == GSL_CONTINUE && iter < max_iter);

    gsl_min_fminimizer_free (s);

    return status;
}