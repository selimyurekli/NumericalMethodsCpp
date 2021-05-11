#pragma once
#include "iostream"
#include "vector"
#include "math.h"
#include "MatrixClass.cpp"



template <typename T>
class LineerAlgebra {

public:
    static vector<T> backwardSubs(Matrix<T> m1, vector<T> v1) {
        vector<T> solutions(m1.col,0);
        int n = m1.row;
        double temp ;
        for (int k = n-1; k >-1 ; k--) {
            temp = 0;
            for (int j = k+1; j <n; j++) {
                temp = temp + (m1.matrix[k][j] * solutions[j]);
            }
            solutions[k] = (v1[k] - temp) / m1.matrix[k][k];
        }
        return solutions;
    }
    static vector<T> forwardSubs(Matrix<T> m1, vector<T> v1) {
        vector<T> solutions(m1.col, 0);
        int n = m1.row;
        double temp;
        for (int k = 0; k<n; k++) {
            temp = 0;
            for (int j = 0; j < k; j++) {
                temp = temp + (m1.matrix[k][j] * solutions[j]);
            }
            solutions[k] = (v1[k] - temp) / m1.matrix[k][k];
        }
        return solutions;
    }
    static Matrix<T>  UpperTriangle(Matrix<T> m1,vector<T>&v1) {
        
        
        //vector<vector<T>> lower(m1.row,vector<T>(m1.row,0));
        double temp=0;
        int n = m1.row;
        for (int k = 0; k < n-1; k++) {
            for (int i = k+1; i <n; i++) {
                temp = m1.matrix[i][k] / m1.matrix[k][k];
                for (int j = 0; j <n; j++) {
                   
                    m1.matrix[i][j] = m1.matrix[i][j] - temp * m1.matrix[k][j];
                    
                }
                
                v1[i] = v1[i] - temp * v1[k];

                
            }
        }
        return m1;

    }
    static void LUDecomposition(Matrix<T> m1,Matrix<T> &upper,Matrix<T> &lower, vector<T>& v1) {
        int n = m1.row;       
        //vector<vector<T>> lower(m1.row,vector<T>(m1.row,0));
        double temp;
        
       
        for (int i = 0; i < n; i++) {
            upper.matrix[0][i] = m1.matrix[0][i];
            (lower).matrix[i][i] = 1;
        }
        
        for (int k = 0; k < n - 1; k++) {
            for (int i = k + 1; i < n; i++) {
                temp = m1.matrix[i][k] / m1.matrix[k][k];
                (lower).matrix[i][k] = temp;
                for (int j = 0; j < n; j++) {

                    m1.matrix[i][j] = m1.matrix[i][j] - temp * m1.matrix[k][j];
                    (upper).matrix[i][j] = m1.matrix[i][j];
                }
                v1[i] = v1[i] - temp * v1[k];
            }
        }
       


    }
    static Matrix<T>  LowerTriangle(Matrix<T> m1, vector<T>& v1) {


        //vector<vector<T>> upper(m1.row, vector<T>(m1.row, 0));
        int temp;
        
        int n = m1.row;
        for (int k = n-1; k >-1; k--) {
            for (int i = k - 1; i > -1; i--) {
                temp = m1.matrix[i][k] / m1.matrix[k][k];
                for (int j = n-1; j > -1; j--) {

                    m1.matrix[i][j] = m1.matrix[i][j] - temp; * m1.matrix[k][j];

                }

                v1[i] = v1[i] - temp * v1[k];


            }
        }
        return m1;

    }
    static Matrix<T> dot(Matrix<T> m1, Matrix<T> m2) {
        Matrix<T>* matrix;
        vector<vector<T>> res(m1.row, vector<T>(m2.col));

      
        double temp;
        if (m1.col == m2.row) {
            for (int i = 0; i < m1.row; i++) {
                for (int k = 0; k < m2.col; k++) {
                    temp = 0;
                    for (int j = 0; j < m2.row; j++) {
                        temp += m1.matrix[i][j] * m2.matrix[j][k];
                    }
                    res[i][k] = temp;
                }

            }
        }
        else {
            cout << "row and col is not equal size." << endl;
            return res;
        }
        matrix = new Matrix<T>(res);
        return *matrix;

    }  
    static Matrix<T>  CholeskyDecomposition(Matrix<T> m2) {
        int n = m2.row;
        for (int k = 0; k < n - 1;k++) {
            m2.matrix[k][k] = sqrt(m2.matrix[k][k]);
            for (int i = k + 1; i < n; i++) {
                m2.matrix[i][k] = m2.matrix[i][k] / m2.matrix[k][k];
                
            }
           
            for (int j = k + 1; j < n; j++) {
                for (int i = j; i < n; i++) {
                    
                    m2.matrix[i][j] = m2.matrix[i][j] - m2.matrix[i][k] * m2.matrix[j][k];
                }
                m2.matrix[k][j] = 0;

            }
         
        
        }
        m2.matrix[n - 1][n - 1] = sqrt(m2.matrix[n - 1][n - 1]);
        
        return m2;
    }
    static Matrix<T> GEPartialPivotting(Matrix<T> m2, vector<T> &v1) {
        int n = m2.row;
        T max;
        int maxIndex;
        for (int i = 0; i < n-1; i++) {//col
            T max = abs(m2[i][i]);
            maxIndex = i;
            for (int j = i; j < n; j++) {//row
                if (max < abs(m2[j][i])) {
                    maxIndex = j;
                    max = abs(m2[j][i]);
                //find max 
                }
                
            }
            m2.swap(i, maxIndex);
            double temp = 0;
            double temp2 = 0;
           
            temp2 = v1[i];
            v1[i] = v1[maxIndex];
            v1[maxIndex] = temp2;
            printVector(v1);
            divideRow(m2, i, m2[i][i]);
            v1[i] /= max;
           
            printVector(v1);
            for (int k = i + 1; k < n; k++) {
                temp = m2[k][i] / m2[i][i];
                for (int j = 0; j < n; j++) {

                    m2[k][j] = m2[k][j] - temp * m2[i][j];

                }

                v1[k] = v1[k] - temp * v1[i];


            }
            
            printVector(v1);
            cout << endl;

        }
        
        return m2;
    };
    static vector<T> LineerLeastSquaresMethod(Matrix<T> A, vector<T> v1) {
        vector<vector<T>> bVec(v1.size(), vector<T>(1));
        Matrix<T> b(bVec);
        
        Matrix<T> AT(A.transpose);
        for (int i = 0; i < v1.size(); i++)
            b[i][0] = v1[i];

        Matrix<T> B(A.col);
        
        Matrix<T> y(A.col);
        B = dot(AT, A);
        y = dot(AT, b);

        Matrix<T> G(B.col);
        G = CholeskyDecomposition(B);
        G.transpose_matrix();
        Matrix<T> GT(G.transpose);
        vector<T> z(v1.size());
        vector<T> yTemp(y.row);
        for (int i = 0; i < y.row; i++)
            yTemp[i] = y[i][0];
        z = forwardSubs(G,yTemp);

        vector<T> x(v1.size());
       
        x = backwardSubs(GT,z);
        return x;
        
    }
    static void printMatrix(Matrix<T> m) {

        for (int i = 0; i < m.row; i++) {
            for (int j = 0; j < m.col; j++) {
                cout << m.matrix[i][j] << " ";
            }
            cout << endl;// printf("\n");
        }
    }
    static void printVector(vector<T> m) {

        for (int i = 0; i < m.size(); i++) {
            cout << m[i] << " ";            
        }
        cout << endl;
    }
    static void printMatrix(vector<vector<T>> m) {

        for (int i = 0; i < m.size(); i++) {
            for (int j = 0; j < m[i].size(); j++) {
                cout << m[i][j] << " ";
            }
            cout << endl;// printf("\n");
        }
    } 
    static void divideRow(Matrix<T>& matrix, size_t row, double scalar) {
        for (int i = 0; i < matrix.col; i++)
            if (matrix[row][i] != 0)
                matrix[row][i] /= scalar;
    };
};


