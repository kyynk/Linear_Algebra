#ifndef MATRIX_H
#define MATRIX_H
#include "bits/stdc++.h"
using namespace std;

class Matrix{
    private:
        int col = -1;
        int row = -1;
        vector <vector<double>> d_vec;
    public:
        void init(vector<vector<double>> input);
        Matrix() = default;
        Matrix(vector<vector<double>> input);
        Matrix(const Matrix& temp);
        ~Matrix() = default;
        void printMatrix();
        vector<vector<double>> getVec() const;
        int getCol() const;
        int getRow() const;
        Matrix &operator=(const Matrix &other);
        Matrix operator+(const Matrix &other);
        Matrix operator-(const Matrix &other);
        Matrix multiplyConstant(double C);
        Matrix operator*(double C);// C is constant
        Matrix operator*(const Matrix &other);
        Matrix transpose();
        bool equal_TorF(const Matrix &other);
        bool operator==(const Matrix &other);
        Matrix inverse();
        Matrix power(int pow);
};
#endif