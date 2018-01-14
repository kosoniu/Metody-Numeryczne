#include <iostream>
#include <math.h>
#include <cstdlib>
#include <vector>

using namespace std;

double HornerMethod(vector<double> a, int x){

    double result = a[0];

    for(int i = 1; i < a.size(); i++){
        result = result*x + a[i];
    }

    return result;
}


vector<double> Derivative(vector<double> multimian){
    vector<double> a;
    int n = multimian.size();

    for(int i = 0; i < n - 1; i++){
        a.push_back(multimian[i]*(n - 1 - i));
    }

    return a;
}

double LaguerreMethod(vector<double> a, double x){
    double z;
    vector<double> firstDerivative;
    vector<double> secondDerivative;
    int n = a.size() - 1;
    firstDerivative = Derivative(a);
    secondDerivative = Derivative(firstDerivative);
    z = x - (n*HornerMethod(a,x))/(HornerMethod(firstDerivative,x) + sqrt((n - 1)*((n-1)*HornerMethod(firstDerivative,x)*HornerMethod(firstDerivative,x) -
    n*HornerMethod(a,x)*HornerMethod(secondDerivative, x))));

    return z;
}



int main(){
    //243z^7 − 486z^6 + 783z^5 − 990z^4 + 558z^3 − 28z^2 − 72z + 16 = 0

    // vector<double> a = {243.0, -486.0, 783.0, -990.0, 558.0, -28.0, -72.0, 16};
    vector<double> a = {1.0, 12.0, 58.0, 134.0, 146.0, 60.0};
    vector<double> tmpVector;
    double x = -3.0;
    double z = LaguerreMethod(a, x);
    cout << z << endl;


    return 0;
}
