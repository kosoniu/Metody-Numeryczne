#include <iostream>
#include <math.h>
#include <cstdlib>
#include <vector>
#include <complex>

#define epsilon 0.0000001

using namespace std;


complex<double> HornerMethod(vector<complex<double>> a, complex<double> x){

    complex<double> result = a[0];

    for(int i = 1; i < a.size(); i++){
        result = result*x + a[i];
    }

    return result;
}

vector<complex<double>> deflation(complex<double> root, vector<complex<double>> a){

    vector<complex<double>> newMultimian;
    root = -root;
    newMultimian.push_back(a[0]);

    for (int i = 1; i < a.size() - 1; i++) {
        complex<double> bi = a[i] - (root)*newMultimian[i - 1];
        newMultimian.push_back(bi);
    }

return newMultimian;
}

vector<complex<double>> Delta(vector<complex<double>> equation){
    complex<double> x1,x2,b,c,a,delta;
    complex<double> four = 4.0;
    complex<double> two = 2.0;

    vector<complex<double>> roots;
    a = equation[0];
    b = equation[1];
    c = equation[2];

    delta = (b*b) - four*(a*c);
    complex<double> up1 = -b + sqrt(delta);
    complex<double> up2 = -b - sqrt(delta);

    x1 = up1 / (two*a);
    x2 = up2 / (two*a);
    roots.push_back(x1);
    roots.push_back(x2);

    return roots;
}


vector<complex<double>> Derivative(vector<complex<double>> multimian){
    vector<complex<double>> a;
    int k = multimian.size();
    complex<double> n((double)k);
    if(multimian.size() == 1){
        a.push_back(multimian[0]);
        return a;
    }

    for(int i = 0; i < k - 1; i++){
        a.push_back(multimian[i]*(n.real() - 1 - i));
    }

    return a;
}

complex<double> LaguerreMethod(vector<complex<double>> &a, complex<double> x){
    complex<double> z, x0;
    vector<complex<double>> firstDerivative;
    vector<complex<double>> secondDerivative;
    int f = a.size() - 1;
    complex<double> n(a.size() - 1);
    complex<double> upper, lowerPlus, lowerMinus;
    firstDerivative = Derivative(a);
    secondDerivative = Derivative(firstDerivative);


    for(int i = 0; i < 100000; i++){
        complex<double> value = HornerMethod(a, x);

        if(abs(value) < epsilon) break;

        complex<double> firstDerivativeValue = HornerMethod(firstDerivative, x);
        complex<double> secondDerivativeValue = HornerMethod(secondDerivative, x);

        upper = (n*HornerMethod(a, x));
        lowerPlus = firstDerivativeValue + sqrt((n - 1.0)*((n - 1.0)*firstDerivativeValue*firstDerivativeValue - n*value*secondDerivativeValue));
        lowerMinus = (firstDerivativeValue - sqrt((n - 1.0)*((n - 1.0)*firstDerivativeValue*firstDerivativeValue - n*value*secondDerivativeValue)));

        if(abs(lowerPlus) > abs(lowerMinus)){
            x0 = (upper / lowerPlus);
        }else{
             x0 = (upper / lowerMinus);
         }

        x -= x0;
        if(abs(x0) < epsilon) break;
    }

    return x;
}

vector<complex<double>> FindRoots(vector<complex<double>> a, complex<double> x0){
    vector<complex<double>> roots;
    vector<complex<double>> activeVector;
    vector<complex<double>> tmpVector;
    activeVector = a;
    complex<double> z, value;
    z = x0;

    for( int i = 0; i < a.size() - 3; i++){
        z = LaguerreMethod(activeVector, x0);
        value = LaguerreMethod(a, z);
        roots.push_back(value);
        tmpVector = deflation(value, activeVector);
        activeVector = tmpVector;
    }

    tmpVector = Delta(activeVector);
    roots.push_back(tmpVector[0]);
    roots.push_back(tmpVector[1]);


    return roots;
}

void DisplayMZ(vector<complex<double>> roots){
    for (int i = 0; i < roots.size(); i++) {
        if(abs(roots[i].real()) < epsilon*1000)
            roots[i].real(0);
        if(abs(roots[i].imag()) < epsilon*1000)
            roots[i].imag(0);
        cout << roots[i] << " ";
    }cout << endl << endl;
}



int main(){

    //243z^7 − 486z^6 + 783z^5 − 990z^4 + 558z^3 − 28z^2 − 72z + 16 = 0

    vector<complex<double>> a1 = {243.0, -486.0, 783.0, -990.0, 558.0, -28.0, -72.0, 16.0};
    vector<complex<double>> a2 = {1.0, 1.0, 3.0, 2.0, -1.0, -3.0, -11.0, -8.0, -12.0, -4.0, -4.0};
    vector<complex<double>> a3 = {1.0, {0.0, 1.0}, -1.0, {0.0, -1.0}, 1.0};
    vector<complex<double>> a = {2.0, -3.0, 10.0};

    // vector<complex<double>> a = {1.0, 12.0, 58.0, 134.0, 146.0, 60.0};
    complex<double> z, value;

    vector<complex<double>> roots;


    complex<double> x1 = 1.0;
    complex<double> x2 = -3.0;
    complex<double> x3 = -1.0;

    cout << "Równanie dla którego liczymy:\n";
    for(int i = 0; i < a1.size(); i++)
        cout << a1[i] << " ";
    cout << endl;
    roots = FindRoots(a1, x1);
    DisplayMZ(roots);

    cout << "Równanie dla którego liczymy:\n";
    for(int i = 0; i < a2.size(); i++)
        cout << a2[i] << " ";
    cout << endl;
    roots = FindRoots(a2, x2);
    DisplayMZ(roots);

    cout << "Równanie dla którego liczymy:\n";
    for(int i = 0; i < a3.size(); i++)
        cout << a3[i] << " ";
    cout << endl;
    roots = FindRoots(a3, x3);
    DisplayMZ(roots);


    return 0;
}
