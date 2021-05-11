#pragma once

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <sstream>
#include <math.h>

#define PI 3.14
using namespace std;

template <typename T>
class Matrix {
public:
    vector<vector<T>> matrix;
    vector<vector<T>> transpose;
    size_t row;
    size_t col;
    int determinant;
    Matrix(vector< vector<T>>& Vector) {
        this->matrix = Vector;
        this->row = Vector.size();
        this->col = Vector[0].size();
        transpose_matrix();
    }
    Matrix(int n) {
        vector<vector<T>> tr(n, vector<T>(n,0));

        this->matrix = tr;
        this->row = n;
        this->col = n;
        transpose_matrix();
    }
    
    //if this function returns const vector, we can just read;
    vector<T>& operator[]( int i){

        return matrix[i];
    };
    Matrix<T> operator / (double scalar) {
        Matrix<T> m(row);
        for (int i = 0; i < int(row); i++) {
            for (int j = 0; j <int( col); j++)
                m.matrix[i][j] = matrix[i][j] / scalar;
        }
        return m;
    };
    void swap(int row1, int row2) {
        vector<T> *vec= &matrix[row1];
        vector<T> *vec2= &matrix[row2];
        vector<T> temp;
        temp = *vec;
        *vec = *vec2;
        *vec2 = temp;
       
    }; 
    
    
    vector<vector<T>> transpose_matrix() {
        vector<vector<T>> tr(this->col,vector<T>(this->row));
        
        for (int i = 0; i < this->row; i++) {
            for (int j = 0; j < this->col; j++) {
                tr[j][i]=this->matrix[i][j];
            }
           
        }
        this->transpose = tr;
        //this->Tr->Tr = &this->matrix;
        return tr;
    }
 
};



