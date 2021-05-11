#pragma once
#include <iostream>
#include <vector>
#include "Methods.cpp"
#include "LineerAlgebra.cpp"
#include "HelperFunctions.cpp"
#include "MatrixClass.cpp"


double TestFunction(double x) {
    return x * x - 2;
    //return cos(x) - x * exp(x);
}
double TestFunctionDerivative(double x) {
    return 2 * x;
}


int main()
{
    vector<vector<double>> v = {    { 2, -1 },
                                    { 1,  2 },
                                    { 1,  1 } };
    
    
    Matrix<double>A(v);
    vector<double> b = {2,1,4};
    vector<double> sol(b.size());
    sol = LineerAlgebra<double>::LineerLeastSquaresMethod(A,b);
    LineerAlgebra<double>::printVector(sol);
    //vector<double> sol;
    //LineerAlgebra<int>::printMatrix(A);
    //LineerAlgebra<double>::printMatrix(A);
//    Matrix<double> upper(A.row);
//    MatrWix<double> lower(A.row);
//    A = (LineerAlgebra<double>::UpperTriangle(A,b));
//    LineerAlgebra<double>::printMatrix(A);
   /* cout << endl;
    A = LineerAlgebra<double>::GEPartialPivotting(A, b);
    LineerAlgebra<double>::printMatrix(A);
    LineerAlgebra<double>::printVector(b);
    sol= LineerAlgebra<double>::backwardSubs(A, b);
    LineerAlgebra<double>::printVector(sol);*/

   

    //double res = Methods::TaylorSeriesSinx(PI, 0, 10);
    //cout<< sin(180)<<endl;
    //double res = Methods::BisectionMethod(0, 3, 0.00001, TestFunction);
    //cout << denemeFunction(res);
    //double res = Methods::RegulaFalsiMethod(0, 3, 0.00001, TestFunction);
    //cout << (res);
    //double res = Methods::NewtonMethod(1, 0.00001, TestFunction, TestFunctionDerivative);
    //cout << res;
    //double res = Methods::SecantMethod(1,2, 0.00001, TestFunction);
    //cout << res;



  
}















