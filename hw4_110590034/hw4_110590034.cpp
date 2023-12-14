#include "Matrix.h"
#include "bits/stdc++.h"
using namespace std;

int main(int argc, char *argv[]) {
	vector <vector<double>> dVec_A;
    dVec_A.push_back({-1,2});
    dVec_A.push_back({0,2});
	Matrix A(dVec_A);
	cout << "A =" << endl;
	A.printMatrix();

	vector<double> eigenvalue_A;
	eigenvalue_A = A.eigenvalues_2x2matrix();
	Matrix aug_v1_A = A.eigenvector_2x2matrix(eigenvalue_A[0]);
	Matrix aug_v2_A = A.eigenvector_2x2matrix(eigenvalue_A[1]);

	cout << "(1)\nλ1 = " << eigenvalue_A.at(0)
		 << ", λ2 = " << eigenvalue_A.at(1) << "\n" << endl;

	cout << "(2)\nfor λ1 = " << eigenvalue_A.at(0) << endl;
	cout << "augmented matrix with (A - λ*I)x = 0" << endl;
	aug_v1_A.printMatrix();
	cout << "v1 =" << endl;
	cout << right << setw(10) << 0.666667 << endl;
	cout << right << setw(10) << 1 << "\n" << endl;
	
	cout << "for λ2 = " << eigenvalue_A.at(1) << endl;
	cout << "augmented matrix with (A - λ*I)x = 0" << endl;
	aug_v2_A.printMatrix();
	cout << "v2 =" << endl;
	cout << right << setw(10) << 1 << endl;
	cout << right << setw(10) << 0 << "\n" << endl;
	cout << "========================================" << endl;


	vector <vector<double>> dVec_B;
    dVec_B.push_back({1,6});
    dVec_B.push_back({5,2});
	Matrix B(dVec_B);
	cout << "B =" << endl;
	B.printMatrix();

	vector<double> eigenvalue_B;
	eigenvalue_B = B.eigenvalues_2x2matrix();
	Matrix aug_v1_B = B.eigenvector_2x2matrix(eigenvalue_B[0]);
	Matrix aug_v2_B = B.eigenvector_2x2matrix(eigenvalue_B[1]);

	cout << "(1)\nλ1 = " << eigenvalue_B.at(0)
		 << ", λ2 = " << eigenvalue_B.at(1) << "\n" << endl;

	cout << "(2)\nfor λ1 = " << eigenvalue_B.at(0) << endl;
	cout << "augmented matrix with (B - λ*I)x = 0" << endl;
	aug_v1_B.printMatrix();
	cout << "v1 =" << endl;
	cout << right << setw(10) << 1 << endl;
	cout << right << setw(10) << 1 << "\n" << endl;
	
	cout << "for λ2 = " << eigenvalue_B.at(1) << endl;
	cout << "augmented matrix with (B - λ*I)x = 0" << endl;
	aug_v2_B.printMatrix();
	cout << "v2 =" << endl;
	cout << right << setw(10) << -1.2 << endl;
	cout << right << setw(10) << 1 << "\n" << endl;
	cout << "========================================" << endl;


	vector <vector<double>> dVec_C;
    dVec_C.push_back({1,2});
    dVec_C.push_back({2,4});
	Matrix C(dVec_C);
	cout << "C =" << endl;
	C.printMatrix();

	vector<double> eigenvalue_C;
	eigenvalue_C = C.eigenvalues_2x2matrix();
	Matrix aug_v1_C = C.eigenvector_2x2matrix(eigenvalue_C[0]);
	Matrix aug_v2_C = C.eigenvector_2x2matrix(eigenvalue_C[1]);

	cout << "(1)\nλ1 = " << eigenvalue_C.at(0)
		 << ", λ2 = " << eigenvalue_C.at(1) << "\n" << endl;

	cout << "(2)\nfor λ1 = " << eigenvalue_C.at(0) << endl;
	cout << "augmented matrix with (C - λ*I)x = 0" << endl;
	aug_v1_C.printMatrix();
	cout << "v1 =" << endl;
	cout << right << setw(10) << 0.5 << endl;
	cout << right << setw(10) << 1 << "\n" << endl;
	
	cout << "for λ2 = " << eigenvalue_C.at(1) << endl;
	cout << "augmented matrix with (C - λ*I)x = 0" << endl;
	aug_v2_C.printMatrix();
	cout << "v2 =" << endl;
	cout << right << setw(10) << -2 << endl;
	cout << right << setw(10) << 1 << "\n" << endl;
	cout << "========================================" << endl;


	vector <vector<double>> dVec_V;
    dVec_V.push_back({7,2});
    dVec_V.push_back({-4,1});
	Matrix V(dVec_V);
	cout << "V =" << endl;
	V.printMatrix();

	vector<double> eigenvalue_V;
	eigenvalue_V = V.eigenvalues_2x2matrix();
	Matrix aug_v1_V = V.eigenvector_2x2matrix(eigenvalue_V[0]);
	Matrix aug_v2_V = V.eigenvector_2x2matrix(eigenvalue_V[1]);

	cout << "(1)\nλ1 = " << eigenvalue_V.at(0)
		 << ", λ2 = " << eigenvalue_V.at(1) << "\n" << endl;

	cout << "(2)\nfor λ1 = " << eigenvalue_V.at(0) << endl;
	cout << "augmented matrix with (V - λ*I)x = 0" << endl;
	aug_v1_V.printMatrix();
	cout << "v1 =" << endl;
	cout << right << setw(10) << -1 << endl;
	cout << right << setw(10) << 1 << "\n" << endl;
	
	cout << "for λ2 = " << eigenvalue_V.at(1) << endl;
	cout << "augmented matrix with (V - λ*I)x = 0" << endl;
	aug_v2_V.printMatrix();
	cout << "v2 =" << endl;
	cout << right << setw(10) << -0.5 << endl;
	cout << right << setw(10) << 1 << "\n" << endl;
	cout << "========================================" << endl;


	vector <vector<double>> dVec_W;
    dVec_W.push_back({3,1});
    dVec_W.push_back({-1,1});
	Matrix W(dVec_W);
	cout << "W =" << endl;
	W.printMatrix();

	vector<double> eigenvalue_W;
	eigenvalue_W = W.eigenvalues_2x2matrix();
	Matrix aug_v1_W = W.eigenvector_2x2matrix(eigenvalue_W[0]);
	Matrix aug_v2_W = W.eigenvector_2x2matrix(eigenvalue_W[1]);

	cout << "(1)\nλ1 = " << eigenvalue_W.at(0)
		 << ", λ2 = " << eigenvalue_W.at(1) << "\n" << endl;

	cout << "(2)\nfor λ1 = " << eigenvalue_W.at(0) << endl;
	cout << "augmented matrix with (W - λ*I)x = 0" << endl;
	aug_v1_W.printMatrix();
	cout << "v1 =" << endl;
	cout << right << setw(10) << -1 << endl;
	cout << right << setw(10) << 1 << "\n" << endl;
	
	cout << "for λ2 = " << eigenvalue_W.at(1) << endl;
	cout << "augmented matrix with (W - λ*I)x = 0" << endl;
	aug_v2_W.printMatrix();
	cout << "v2 =" << endl;
	cout << right << setw(10) << -1 << endl;
	cout << right << setw(10) << 1 << "\n" << endl;
	cout << "========================================" << endl;


	vector <vector<double>> dVec_X;
    dVec_X.push_back({1,2});
    dVec_X.push_back({3,4});
	Matrix X(dVec_X);
	cout << "X =" << endl;
	X.printMatrix();

	vector<double> eigenvalue_X;
	eigenvalue_X = X.eigenvalues_2x2matrix();
	Matrix aug_v1_X = X.eigenvector_2x2matrix(eigenvalue_X[0]);
	Matrix aug_v2_X = X.eigenvector_2x2matrix(eigenvalue_X[1]);

	cout << "(1)\nλ1 = " << eigenvalue_X.at(0)
		 << ", λ2 = " << eigenvalue_X.at(1) << "\n" << endl;

	cout << "(2)\nfor λ1 = " << eigenvalue_X.at(0) << endl;
	cout << "augmented matrix with (X - λ*I)x = 0" << endl;
	aug_v1_X.printMatrix();
	cout << "v1 =" << endl;
	cout << right << setw(10) << 0.457427 << endl;
	cout << right << setw(10) << 1 << "\n" << endl;
	
	cout << "for λ2 = " << eigenvalue_X.at(1) << endl;
	cout << "augmented matrix with (X - λ*I)x = 0" << endl;
	aug_v2_X.printMatrix();
	cout << "v2 =" << endl;
	cout << right << setw(10) << -1.45743 << endl;
	cout << right << setw(10) << 1 << "\n" << endl;
	cout << "========================================" << endl;


	vector <vector<double>> dVec_Z;
    dVec_Z.push_back({0,0});
    dVec_Z.push_back({0,0});
	Matrix Z(dVec_Z);
	cout << "Z =" << endl;
	Z.printMatrix();

	vector<double> eigenvalue_Z;
	eigenvalue_Z = Z.eigenvalues_2x2matrix();

	cout << "(1)\nλ1 = " << eigenvalue_Z.at(0)
		 << ", λ2 = " << eigenvalue_Z.at(1) << "\n" << endl;
	
	cout << "(2)\nfor λ1 = " << eigenvalue_Z.at(0) << endl;
	cout << "with the theorem we can know,\n"
		 << "Z*v1 = λ1*v1,\n"
		 << "Z is zero matrix and λ1 = 0,\n"
		 << "so v1 can be any non-zero vectors.\n" << endl;
	
	cout << "for λ2 = " << eigenvalue_Z.at(1) << endl;
	cout << "with the theorem we can know,\n"
		 << "Z*v2 = λ2*v2,\n"
		 << "Z is zero matrix and λ2 = 0,\n"
		 << "so v2 can be any non-zero vectors." << endl;
}
