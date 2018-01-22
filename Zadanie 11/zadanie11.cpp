#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

const double epsilon = 0.00000001;


double f(double x)
{
  return (x*x - 1)*(sinh(x)*sinh(x)*sinh(x));
}

double fx(double x){
    double a = sqrt(2.0-x*x) / sqrt(2.0);
    double b = (x - 1.0);

    return (a - 0.5)*(a - 0.5) + b*b - 1.0/4.0;
}

double y(double x, double y){
    return 2.0*x*x + y*y - 2.0;
}


double secantMethod(double x1, double x2){
    double f1, f2, f3, x3, tmpX3;

    int i = 0;

    while(1)
  {
      f1 = fx(x1);
      f2 = fx(x2);
      x3 = (f1 * x2 - f2 * x1)/( f1 - f2);
      f3 = fx(x3);

    if(f1 == f2 )
    {
      cout << "Złe punkty startowe, f1 = f2\n";
      break;
    }

    if((abs(x3 - tmpX3) < epsilon) && fx(x3) < epsilon) break;
    cout << "W x3 = "<< x3 << ", f(x3) = " << f3 << endl;
    x2 = x1;
    x1 = x3;
    tmpX3 = x3;

    i++;
  }

    cout << "Ilość iteracji: " << i << endl;

    return x3;
}

    double InverseInterpolation(double x1, double x2, double x3){
        double x0, y;
        double tmpX = 0;
        double x[] = {x1, x2, x3};
        double fy[] = {fx(x1), fx(x2), fx(x3)};
        int i = 0;

        while(1){
            i++;
            x0 = (x[0]*fy[1]*fy[2])/((fy[0] - fy[1] * (fy[0] - fy[2]))) + (x[1]*fy[0]*fy[2])/((fy[1] - fy[0] * (fy[1] - fy[2])))
            + (x[2]*fy[0]*fy[1])/((fy[2] - fy[0] * (fy[2] - fy[1])));
            x1 = x2;
            x2 = x3;
            x3 = x0;
            y = fx(x0);
            x[0] = x1;
            fy[0] = fx(x1);
            x[1] = x2;
            fy[1] = fx(x2);
            x[2] = x0;
            fy[2] = fx(x0);
            cout << "W x = "<< x0 << ", f(x) = " << fx(x0) << endl;

            if(abs(x0 - tmpX) <= epsilon){
                cout << "W x = "<< x0 << ", f(x) = " << fx(x0) << endl;
                i++;
                break;
            }

            // if(abs(f(x0)) <= epsilon){
            //     cout << "W x = "<< x0 << ", f(x) = " << f(x0) << endl;
            //     i++;
            //
            //     break;
            // }

            tmpX = x0;
        }
        cout << "Ilość iteracji: " << i << endl;

        return x0;
    }

    double fRand(double fMin, double fMax)
    {
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
    }


int main()
{

  double x0,f0,f1,f2;
  double value;
  // srand(time(0));
  //
  // double x1 = fRand(0,1);
  // double x2 = fRand(0,1);
  // double x3 = fRand(0,1);
  // if(x2 < x1 || x3 < x2){
  //     while((x1 > x2) && (x2 > x3)){
  //         x2 = fRand(0,1);
  //         x1 = fRand(0,1);
  //         x3 = fRand(0,1);
  //     }
  // }


  double x1 = 0.2;
  double x2 = 1.1;
  double x3 = 1.3;

      cout << setprecision(8)     // 8 cyfr po przecinku
           << fixed;              // format stałoprzecinkowy

    cout << "x1 = " << x1 << " x2 = " << x2 << " x3 = " << x3 << endl;
    value = secantMethod(x1, x2);
    cout << "Miejsce zerowe jest w: " << value << endl;
    // value = InverseInterpolation(x1, x2, x3);
    // cout << "Miejsce zerowe jest w: " << value << endl;


  return 0;
}
