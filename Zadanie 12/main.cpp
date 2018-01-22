#include <math.h>
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

#define epsilon 0.000001

using namespace std;

typedef double( * function )( double );

double fx(double x){
    double a = sqrt(2.0-x*x) / sqrt(2.0);
    double b = (x - 1.0);

    return (a - 0.5)*(a - 0.5) + b*b - 1.0/4.0;
}

double yx(double x){

    return 0;
}

double FunctionValue(double x, function pDzialanie){
    return pDzialanie(x);
}


double findD( double a, double b, double c, function func){
    double d = 0;
    double fa = FunctionValue(a,func);
    double fb = FunctionValue(b,func);
    double fc = FunctionValue(c,func);

    double up = ((a*a)*(fc - fb)) + ((b*b)*(fa - fc)) + ((c*c)*(fb - fa));
    double down = ((a)*(fc - fb)) + ((b)*(fa - fc)) + ((c)*(fb - fa));
    d = 0.5*(up/down);

    return d;
}


double BrentMethod(double a, double b, double c, function func){
    double fa = FunctionValue(a, func);
    double fb = FunctionValue(b, func);
    double fc = FunctionValue(c, func);
    double d, fd, interval, newInterval;
    double tmpA, tmpB, tmpC, tmpFa, tmpFb, tmpFc;
    double tmpD = 0;
    int i = 0;
    bool flag = false;


    while(1){
        interval = ((c - a) / 2);
        cout << "liczmy dla a: " << a << " b: " << b << " c: " << c << endl;
        d = findD(a, b, c, fx);
        cout << "d dla interpolacj parabolicznej: " << d << endl;
        fd = FunctionValue(d, func);
        cout << fd << " " << fb << endl;

        if((a < d) && (d < c)){
            tmpA = a;
            tmpB = b;
            tmpC = c;
            tmpFa = fa;
            tmpFb = fb;
            tmpFc = fc;
                if( fd < fb){
                    if( d < b){
                        c = b;
                        fc = fb;
                        b = d;
                        fb = fd;
                    }else if(d > b){
                        a = b;
                        fa = fb;
                        b = d;
                        fb = fd;
                }
            }else if (fd > fb){
                if( d < b){
                    a = d;
                    fa = fd;
                }
                else if(d > b){
                    c = d;
                    fc = fd;
                }
            }

            newInterval = (c - a);

            if(newInterval > interval){
                flag = true;
                a = tmpA;
                b = tmpB;
                c = tmpC;
                fa = tmpFa;
                fb = tmpFb;
                fc = tmpFc;
            }

        }else if((a > d) || (d > c)){
            flag = true;
            cout << "wypadl z przedzialu" << endl;
        }

        if(flag == true){
            cout << "wykonuje alternatywe\n";
            d = (c + a) / 2;
            cout << "d dla bisekcji: " << d << endl;
            fd = FunctionValue(d, func);
            cout << fd << " " << fb << endl;
            if(abs(fd) < epsilon) break;
                if( fd < fb){
                    if( d < b){
                        c = b;
                        fc = fb;
                        b = d;
                        fb = fd;
                    }else if(d > b){
                        a = b;
                        fa = fb;
                        b = d;
                        fb = fd;
                    }
                }else if (fd > fb){
                    if( d < b){
                        a = d;
                        fa = fd;
                    }
                    else if(d > b){
                        c = d;
                        fc = fd;
                    }
                }
        }
        flag = false;
        i++;
        cout << "po " << i <<  " iteracji a: " << a << " b: " << b << " c: " << c << endl << endl;
        if(abs(c - a) < epsilon) break;
        tmpD = d;
    }

    cout << "ilosc iteracji " << i << endl;

    return d;
}


int main(){

    // tak wybieramy punkty: a < b < c : f(a) > f(b), f(c) > f(b)
    cout << setprecision(8)     // 8 cyfr po przecinku
         << fixed;
    double a = 0.5;
    double b = 1.2;
    double c = 1.4;
    double x = BrentMethod(a, b, c, fx);

    // cout << x <<endl;
    cout << FunctionValue(1.38943, fx) << endl;


    return 0;
}
