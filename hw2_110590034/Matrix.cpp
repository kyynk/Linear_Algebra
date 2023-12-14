#include "bits/stdc++.h"
#include "Matrix.h"
using namespace std;

void Matrix::init(vector<vector<double>> input){
    d_vec = input;
    row = input.size();
    col = input[0].size();
}
Matrix::Matrix(vector<vector<double>> input){
    init(input);
}
Matrix::Matrix(const Matrix& temp){
    init(temp.getVec());
}
void Matrix::printMatrix(){
    for(int i = 0; i < d_vec.size(); i++){
        for(int j = 0; j < d_vec[i].size(); j++){
            cout << right << setw(10) << d_vec[i][j];
        }
        cout << "\n";
    }
    cout << endl;
}
vector<vector<double>> Matrix::getVec() const {
    return d_vec;
}
int Matrix::getCol() const {
    return col;
}
int Matrix::getRow() const {
    return row;
}
Matrix &Matrix::operator=(const Matrix &other){
    if(this != &other){
        init(other.getVec());
    }
    return *this;
}
Matrix Matrix::operator+(const Matrix &other){
    if (this->col != other.getCol() || this->row != other.getRow())
        throw std::string("matrix size is not same");
    
    vector<vector<double>> temp = this->d_vec;
    for(int i = 0; i < this->row; i++){
        for(int j = 0; j < this->col; j++){
            temp[i][j] += other.getVec()[i][j];
        }
    }
    Matrix temp_matrix(temp);
    return temp_matrix;
}
Matrix Matrix::operator-(const Matrix &other){
    if (this->col != other.getCol() || this->row != other.getRow())
        throw std::string("matrix size is not same");
    
    vector<vector<double>> temp = this->d_vec;
    for(int i = 0; i < this->row; i++){
        for(int j = 0; j < this->col; j++){
            temp[i][j] -= other.getVec()[i][j];
        }
    }
    Matrix temp_matrix(temp);
    return temp_matrix;
}
Matrix Matrix::multiplyConstant(double C){
    vector<vector<double>> temp = this->d_vec;
    for(int i = 0; i < this->row; i++){
        for(int j = 0; j < this->col; j++){
            temp[i][j] *= C;
        }
    }
    Matrix temp_matrix(temp);
    return temp_matrix;
}
Matrix Matrix::operator*(double C){ // C is constant
    vector<vector<double>> temp = this->d_vec;
    for(int i = 0; i < this->d_vec.size(); i++){
        for(int j = 0; j < this->d_vec[i].size(); j++){
            temp[i][j] *= C;
        }
    }
    Matrix temp_matrix(temp);
    return temp_matrix;
}
Matrix Matrix::operator*(const Matrix &other){
    if (this->col != other.getRow())
        throw std::string("matrix size wrong");
    
    vector<vector<double>> temp;
    vector<double> temp_row;
    // e.g. 3x2 matrix * 2x1 matrix = 3x1 matrix
    //      ixk matrix * kxj matrix = ixj matrix
    for(int i = 0; i < this->row; i++){
        for(int j = 0; j < other.getCol(); j++){
            double tt = 0;
            for(int k = 0;k <other.getRow(); k++){  // other.getRow() = this->col
                tt = tt + this->d_vec[i][k] * other.getVec()[k][j];
            }
            temp_row.push_back(tt);
        }
        temp.push_back(temp_row);
        temp_row.clear();
    }
    Matrix temp_matrix(temp);
    return temp_matrix;
}
Matrix Matrix::transpose(){
    vector<vector<double>> temp;
    vector<double> temp_row;
    // original  matrix jxi
    // transpose matrix ixj
    for(int i = 0; i < this->col; i++){
        for(int j = 0; j < this->row; j++){
            temp_row.push_back(this->d_vec[j][i]);
        }
        temp.push_back(temp_row);
        temp_row.clear();
    }
    Matrix temp_matrix(temp);
    return temp_matrix;
}
bool Matrix::equal_TorF(const Matrix &other){
    if (this->row != other.getRow() || this->col != other.getCol())
        throw std::string("not same size");
    if (this->d_vec == other.getVec())
        return true;
    return false;
}
bool Matrix::operator==(const Matrix &other){
    if (this->row != other.getRow() || this->col != other.getCol())
        throw std::string("not same size");
    if (this->d_vec == other.getVec())
        return true;
    return false;
}
Matrix Matrix::inverse(){
    if (this->row != this->col)
        throw std::string("is not nxn matrix");
    vector<vector<double>> temp_AtoI(this->d_vec);
    vector<vector<double>> I;
    vector<double> temp_row;
    // matrix A is nxn
    // create matrix I nxn
    temp_row.clear();
    for(int i = 0; i < this->row; i++){
        for(int j = 0; j < this->col; j++){
            double tt = 0;
            if (i == j) temp_row.push_back(tt+1);
            else temp_row.push_back(tt);
        }
        I.push_back(temp_row);
        temp_row.clear();
    }
    vector<vector<double>> temp_ItoA_inv(I);
    
    // row reduction to echelon form
    
    for(int i = 0; i < this->col; i++){
        int pivot = -1;
        // find pivot in where row
        for(int j = i; j < this->row; j++){
            if(temp_AtoI[j][i] != 0) pivot = j;
            if(pivot != -1) break;
        }
        
         // if this column doesn't have pivot, then this nxn matrix is not invertible
        if(pivot == -1)
            throw std::string("not have pivot in every column, this matrix is not invertible");
        
        // if pivot is not in the correct position, then interchange
        // e.g. pivot in [row2,col1] then row1 and row2 interchange
        if(pivot != i){
            temp_AtoI[pivot], temp_AtoI[i] = temp_AtoI[i], temp_AtoI[pivot];
            temp_ItoA_inv[pivot], temp_ItoA_inv[i] = temp_ItoA_inv[i], temp_ItoA_inv[pivot];
            pivot = i;
        }

        for(int j = pivot+1; j < this->row; j++){
            if (temp_AtoI[j][i] == 0) continue;
            double d_constant = -1 * temp_AtoI[j][i] / temp_AtoI[pivot][i];
            for(int k = i; k < this->col; k++){
                temp_AtoI[j][k] += temp_AtoI[pivot][k] * d_constant;
                temp_ItoA_inv[j][k] += temp_ItoA_inv[pivot][k] * d_constant;
            }
        }
    }
    // echelon form to reduced echelon form
    for(int i = this->row-1; i > -1; i--){
        if (temp_AtoI[i][i] != 1){
            double d_constant = temp_AtoI[i][i];
            // j = col, i = row or col
            // let pivot to 1
            for(int j = i; j < this->col; j++) temp_AtoI[i][j] /= d_constant;
            for(int j = 0; j < this->col; j++) temp_ItoA_inv[i][j] /= d_constant;

            // j = row, k = col, i = row or col
            for(int j = i-1; j > -1; j--){
                d_constant = -1 * temp_AtoI[j][i];
                for(int k = i; k < this->col; k++)
                    temp_AtoI[j][k] += d_constant * temp_AtoI[i][k];
                for(int k = 0; k < this->col; k++)
                    temp_ItoA_inv[j][k] += d_constant * temp_ItoA_inv[i][k];
            }
        }
    }
    // check [A I] = [I inverse(A)]
    if (temp_AtoI != I)
        throw std::string("is not invertible");
    cout << "is invertible" << endl;
    Matrix temp_matrix(temp_ItoA_inv);
    return temp_matrix;
}
Matrix Matrix::power(int pow){
    vector<vector<double>> I;
    vector<double> temp_row;
    // create matrix I nxn
    temp_row.clear();
    for(int i = 0; i < this->row; i++){
        for(int j = 0; j < this->col; j++){
            double tt = 0;
            if (i == j) temp_row.push_back(tt+1);
            else temp_row.push_back(tt);
        }
        I.push_back(temp_row);
        temp_row.clear();
    }
    Matrix temp_power(I);
    for(int i = 0; i < pow; i++) temp_power = temp_power * (*this);
    return temp_power;
}