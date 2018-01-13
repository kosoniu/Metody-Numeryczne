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


double secantMethod(double x1, double x2){
    double f1, f2, f3, x3, tmpX3;

    int i = 0;

    while(1)
  {
      f1 = f(x1);
      f2 = f(x2);
      x3 = (f1 * x2 - f2 * x1)/( f1 - f2);
      f3 = f(x3);

    if(f1 == f2 )
    {
      cout << "Złe punkty startowe, f1 = f2\n";
      break;
    }

    if(abs(x3 - tmpX3) <= epsilon) break;
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
        double fx[] = {f(x1), f(x2), f(x3)};
        int i = 0;

        while(1){
            i++;
            x0 = (x[0]*fx[1]*fx[2])/((fx[0] - fx[1] * (fx[0] - fx[2]))) + (x[1]*fx[0]*fx[2])/((fx[1] - fx[0] * (fx[1] - fx[2])))
            + (x[2]*fx[0]*fx[1])/((fx[2] - fx[0] * (fx[2] - fx[1])));
            x1 = x2;
            x2 = x3;
            x3 = x0;
            y = f(x0);
            x[0] = x1;
            fx[0] = f(x1);
            x[1] = x2;
            fx[1] = f(x2);
            x[2] = x0;
            fx[2] = f(x0);
            cout << "W x = "<< x0 << ", f(x) = " << f(x0) << endl;

            if(abs(x0 - tmpX) <= epsilon){
                cout << "W x = "<< x0 << ", f(x) = " << f(x0) << endl;
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
  srand(time(0));

  double x1 = fRand(0,1);
  double x2 = fRand(0,1);
  double x3 = fRand(0,1);

  // double x1 = -.96;
  // double x2 = -.76;
  // double x3 = -.65;

      cout << setprecision(16)     // 8 cyfr po przecinku
           << fixed;              // format stałoprzecinkowy

    cout << "x1 = " << x1 << " x2 = " << x2 << " x3 = " << x3 << endl;
    value = secantMethod(x1, x2);
    cout << "Miejsce zerowe jest w: " << value << endl;
    value = InverseInterpolation(x1, x2, x3);
    cout << "Miejsce zerowe jest w: " << value << endl;


  return 0;
}
