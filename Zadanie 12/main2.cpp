#include <math.h>
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

#define epsilon 0.0000001

using namespace std;

typedef double( * function )( double );

double fx(double x){
    double a = sqrt(2.0-x*x) / sqrt(2.0);
    double b = (x - 1.0);

    return (a - 0.5)*(a - 0.5) + b*b - 1.0/4.0;
}


double yx(double x, double y){
    return 2.0*x*x + y*y - 2.0;
}

double fxPrim(double x){
 double up = sqrt(2.0)*x*(-0.5 + (sqrt(2.0 - x*x) / sqrt(2.0)));
 double down = sqrt(2.0 - x*x);

 return 2.0*(-1.0 + x) - (up / down);
}

double FunctionValue(double x, function pDzialanie){
    return pDzialanie(x);
}


double secantMethodFirstFunction(double x1, double x2){
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

double secantMethodSecondFunctionFunction(double x1, double x2, double y){
    double f1, f2, f3, x3, tmpX3;

    int i = 0;

    while(1)
  {
      f1 = yx(x1, y);
      f2 = yx(x2, y);
      x3 = (f1 * x2 - f2 * x1)/( f1 - f2);
      f3 = yx(x3, y);

    if(f1 == f2 )
    {
      cout << "Złe punkty startowe, f1 = f2\n";
      break;
    }

    if((abs(x3 - tmpX3) < epsilon) && yx(x3, y) < epsilon) break;
    cout << "W x3 = "<< x3 << ", f(x3) = " << f3 << endl;
    x2 = x1;
    x1 = x3;
    tmpX3 = x3;

    i++;
  }

    cout << "Ilość iteracji: " << i << endl;

    return x3;
}

double newtonMethod(double x){
    double x0 = x;
    double xi;
    int i = 0;
    while(1){
        i++;
        xi = x0 - fx(x0)/fxPrim(x0);
        cout << "W xi = "<< xi << ", f(xi) = " << fx(xi) << endl;
        if(abs(x0 - xi) < epsilon) break;
        x0 = xi;
    }
    cout << "ilosc iteracji dla metody Newtona: " << i << endl;
    return xi;
}

int main(){

    cout << setprecision(10)     // 8 cyfr po przecinku
         << fixed;
    double a = 0.2;
    double b = 0.5;
    double c = 1.2;
    // double y0 = secantMethodFirstFunction(a,b);
    double y0 = newtonMethod(b);
    double x0 = secantMethodSecondFunctionFunction(a,b,y0);
    cout << y0 <<endl;
    cout << x0 << endl;


    return 0;
}
