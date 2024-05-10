#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>

using namespace std;

double diff_1 (int i, double h, const double *y){
    return ((y[i+1]-y[i-1])/(2*h)) ;
}

double diff_1_e (double x){
    return ((4*x*x*x-4*x)/(x*x*x*x-2*x*x+3));
}

double diff_2 (int i, double h, const double *y){
    return ((y[i+1]+y[i-1]-2*y[i])/(h*h)) ;
}

double diff_2_2h (int i, double h, const double *y){
    return ((y[i+2]+y[i-2]-2*y[i])/(4*h*h)) ;}


double diff_2_e (double x){
    return (-4*x*x*x*x*x*x+4*x*x*x*x+28*x*x-12)/pow(x*x*x*x-2*x*x+3,2);
}


int main() {

    int n;
    double h;

    ifstream func("result_ie.txt");
    func >> n >> h;
    double x[n],y[n];


    for (int i = 0; i < n+2; i++) {
        func >> x[i] >> y[i];}
    func.close();

    cout << "f'(x)      diff_1    diff_1_e                  diff_2  diff_2_e" << endl;
    ofstream result("result_diff.txt");
    for (int i=1; i < n; i++){
        cout <<"f'("<<x[i]<<") = "<< diff_1(i,h,y)<<" = "<<diff_1_e(x[i])<< ";      f''("<<x[i]<<") = "<< diff_2(i,h,y) <<" = "<<diff_2_e(x[i]);
    if (i%2==0)cout << " eps " << (diff_2(i,h,y)-diff_2_2h(i,h,y))/3;
    cout << endl;
    }


    result.close();

    return 0;
}
