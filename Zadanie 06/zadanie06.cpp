#include <iostream>
#include <math.h>
#include <cstdlib>
#include <vector>
#include <complex>

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


vector<complex<double>> Derivative(vector<complex<double>> multimian){
    vector<complex<double>> a;
    complex<double> n = multimian.size();
    int k = multimian.size();
    if(multimian.size() == 1){
        a.push_back(multimian[0]);
        return a;
    }

    for(int i = 0; i < k - 1; i++){
        a.push_back(multimian[i]*(n.real() - 1 - i));
    }

    return a;
}

complex<double> LaguerreMethod(vector<complex<double>> a, complex<double> x){
    complex<double> z;
    vector<complex<double>> firstDerivative;
    vector<complex<double>> secondDerivative;
    complex<double> n = a.size() - 1.0;
    complex<double> upper, lowerPlus, lowerMinus;
    firstDerivative = Derivative(a);
    secondDerivative = Derivative(firstDerivative);
    double epsilon = 0.0000001;


    for(int i = 0; i < 100; i++){
        complex<double> value = HornerMethod(a, x);

        if(abs(value) < epsilon) break;

        // complex<double> firstDerivativeValue = HornerMethod(firstDerivative, x);
        // complex<double> secondDerivativeValue = HornerMethod(secondDerivative, x);
        //
        // complex<double> G = firstDerivativeValue / value;
        // complex<double> H = G*G - secondDerivativeValue - value;
        // complex<double> R = sqrt((n - 1.0) * (H * n - G*G));
        //
        // complex<double> D1 = G + R;
        // complex<double> D2 = G - R;
        //
        // complex<double> M;
        //
        // if(abs(D1) > abs(D2)) M = D1;
        // else M = D2;

        // complex<double> x0 = n / M;


        upper = (n*HornerMethod(a, x));
        lowerPlus = (HornerMethod(firstDerivative, x) + sqrt((n.real() - 1.0)*((n.real() - 1.0)*HornerMethod(firstDerivative, x)*HornerMethod(firstDerivative, x) - n*HornerMethod(a, x)*HornerMethod(secondDerivative, x))));
        lowerMinus = (HornerMethod(firstDerivative, x) - sqrt((n.real() - 1.0)*((n.real() - 1.0)*HornerMethod(firstDerivative, x)*HornerMethod(firstDerivative, x) - n*HornerMethod(a, x)*HornerMethod(secondDerivative, x))));

        if(abs(lowerPlus) > abs(lowerMinus)){
            z = x - (upper / lowerPlus);
            // cout << lowerPlus << "<- " << lowerMinus << endl;
        }else{
             z = x - (upper / lowerMinus);
             // cout << lowerPlus << " ->" << lowerMinus << endl;
         }

         complex<double> k = n / z;

        x -= k;
        if(abs(k) < epsilon) break;
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

    for( int i = 0; i < a.size() - 1; i++){
        for (int i = 0; i < activeVector.size(); i++) {
            cout << activeVector[i] << " ";
        } cout << endl;
        z = LaguerreMethod(activeVector, x0);
        value = LaguerreMethod(a, z);
        roots.push_back(value);
        cout << "z' = " << z << ", z = " << value << endl << endl;
        tmpVector = deflation(value, activeVector);
        activeVector = tmpVector;
    }

    return roots;
}



int main(){
    //243z^7 − 486z^6 + 783z^5 − 990z^4 + 558z^3 − 28z^2 − 72z + 16 = 0

    // vector<complex<double>> a = {243.0, -486.0, 783.0, -990.0, 558.0, -28.0, -72.0, 16};
    vector<complex<double>> a = {1.0, 12.0, 58.0, 134.0, 146.0, 60.0};
    // vector<complex<double>> b = {1.0, 8.82467, 27.6289, 25.5325};
    complex<double> z, value;

    vector<complex<double>> tmpVector;

    complex<double> x = -3.0;

    tmpVector = FindRoots(a, x);
    for (int i = 0; i < tmpVector.size(); i++) {
        cout << tmpVector[i] << " ";
    }
    cout << endl;

    return 0;
}
